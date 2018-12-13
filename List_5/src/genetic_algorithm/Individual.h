//
// Created by fig_bar98 on 22.11.18.
//

#ifndef LIST_4_INDIVIDUAL_H
#define LIST_4_INDIVIDUAL_H

#include <vector>
#include "../knapsack_problem/KnapsackProblem.h"
#include "utils/Tools.h"
#include <random>


using namespace std;

template<typename T>
class Individual {

public:
    Individual(KnapsackProblem<T> &instOfProblem, double mutProb);

    Individual(KnapsackProblem<T> &instOfProblem, T *genotype, double mutProb);

    Individual(Individual<T> &copyOther);

    ~Individual();

    void operator++(int);

    Individual<T> *operator+(Individual<T> &crossWith);

    Individual<T> *operator=(Individual<T> &copyOther);

    double getFitness() const;

    T *getGenotype() const;

    int getNOfGenes() const;

private:
    double mutProb;
    T *genotype;
    int nOfGenes;
    double fitness;
    KnapsackProblem<T> *problem;

    void mutate();

    vector<Individual *> *cross(Individual &crossWith);

    void calcFitness();

};

template<typename T>
Individual<T>::Individual(KnapsackProblem<T> &instOfProblem, double mutProb) {
    this->problem = &instOfProblem;
    this->nOfGenes = instOfProblem.getNOfItems();
    this->genotype = new T[nOfGenes];
    this->mutProb = mutProb;
    //calcFitness();
}

template<typename T>
Individual<T>::Individual(KnapsackProblem<T> &instOfProblem, T *genotype, double mutProb) {
    this->problem = &instOfProblem;
    this->nOfGenes = instOfProblem.getNOfItems();
    this->genotype = genotype;
    this->mutProb = mutProb;
    calcFitness();
}

template<typename T>
Individual<T>::Individual(Individual<T> &copyOther) {
    this->problem = copyOther.problem;
    this->nOfGenes = copyOther.nOfGenes;
    this->genotype = new T[nOfGenes];
    this->mutProb = copyOther.mutProb;

    for (int i = 0; i < nOfGenes; ++i) {
        genotype[i] = copyOther.genotype[i];
    }
    calcFitness();
}

template<typename T>
Individual<T>::~Individual() {
    delete[] genotype;
}

template<>
void Individual<bool>::calcFitness() {
    double weightSum = 0;
    double valueSum = 0;
    double bagCapacity = problem->getBagCapacity();
    vector<Item *> *listOfItems = problem->getItemList();

    for (int i = 0; i < nOfGenes; ++i) {
        if (genotype[i]) {
            Item *current = (*listOfItems)[i];
            weightSum += current->getWeight();
            valueSum += current->getValue();
        }
    }
    this->fitness = (weightSum <= bagCapacity) ? valueSum : 0;
}

template<typename T>
void Individual<T>::calcFitness() {
    double weightSum = 0;
    double valueSum = 0;
    double bagCapacity = problem->getBagCapacity();
    vector<Item *> *listOfItems = problem->getItemList();

    for (int i = 0; i < nOfGenes; ++i) {
        if (genotype[i] > T()) {
            Item *current = (*listOfItems)[i];
            weightSum += (current->getWeight() * genotype[i]);
            valueSum += (current->getValue() * genotype[i]);
        }
    }
    this->fitness = (weightSum <= bagCapacity) ? valueSum : T();
}

template<typename T>
void Individual<T>::mutate() {
    random_device rd;
    mt19937 gen(rd());
    for (int i = 0; i < nOfGenes; ++i) {
        if (((double) Tools::generateRandomNumber(0, 100) / 100.0) < mutProb) {
            uniform_real_distribution<> generate(-(problem->getMaxAmountOfItem().at(i) / 2),
                                                 problem->getMaxAmountOfItem().at(i));
            T mutatedFactor = (T) generate(gen);
            mutatedFactor > T() ? genotype[i] = mutatedFactor : genotype[i] = T();
        }
    }
    calcFitness();
}

template<>
void Individual<bool>::mutate() {
    for (int i = 0; i < nOfGenes; ++i) {
        if (((double) Tools::generateRandomNumber(0, 100) / 100.0) < mutProb) {
            genotype[i] = !genotype[i];
        }
    }
    calcFitness();
}

template<typename T>
void Individual<T>::operator++(int) {
    this->mutate();
}

template<typename T>
Individual<T> *Individual<T>::operator+(Individual<T> &crossWith) {
    vector<Individual *> *offspring = this->cross(crossWith);
    Individual<T> *descendant = offspring->at(0);
    delete offspring->at(1);
    delete offspring;
    return descendant;
}

template<typename T>
Individual<T> *Individual<T>::operator=(Individual<T> &copyOther) {
    this->problem = copyOther.problem;
    if (genotype)
        delete[] genotype;
    this->nOfGenes = copyOther.nOfGenes;
    this->genotype = new int[nOfGenes];
    this->mutProb = copyOther.mutProb;

    for (int i = 0; i < nOfGenes; ++i) {
        genotype[i] = copyOther.genotype[i];
    }
    calcFitness();
    return this;
}

template<typename T>
vector<Individual<T> *> *Individual<T>::cross(Individual<T> &crossWith) {
    vector<Individual<T> *> *offspring = new vector<Individual<T> *>;

    int crossingIndex = Tools::generateRandomNumber(1, nOfGenes - 1);

    T *fstDescendantGenotype = new T[nOfGenes];
    T *sndDescendantGenotype = new T[nOfGenes];

    for (int i = 0; i < crossingIndex; ++i) {
        fstDescendantGenotype[i] = this->genotype[i];
        sndDescendantGenotype[i] = crossWith.genotype[i];
    }
    for (int j = crossingIndex; j < nOfGenes; ++j) {
        fstDescendantGenotype[j] = crossWith.genotype[j];
        sndDescendantGenotype[j] = this->genotype[j];
    }

    Individual<T> *fstDescendant = new Individual(*(this->problem), fstDescendantGenotype, mutProb);
    Individual<T> *sndDescendant = new Individual(*(this->problem), sndDescendantGenotype, mutProb);

    offspring->push_back(fstDescendant);
    offspring->push_back(sndDescendant);

    return offspring;
}

template<typename T>
double Individual<T>::getFitness() const {
    return fitness;
}

template<typename T>
T *Individual<T>::getGenotype() const {
    return genotype;
}

template<typename T>
int Individual<T>::getNOfGenes() const {
    return nOfGenes;
}

#endif //LIST_4_INDIVIDUAL_H
