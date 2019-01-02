//
// Created by fig_bar98 on 29.11.18.
//

#ifndef LIST_4_GENETICALGORITHM_H
#define LIST_4_GENETICALGORITHM_H


#define DEFAULT_POPSIZE 4

#define DEFAULT_CROSSPROB 0.75

#define DEFAULT_MUTPROB 0.25


#include "Individual.h"
#include "../knapsack_problem/KnapsackProblem.h"
#include <chrono>
#include <iostream>
#include <random>

using namespace std;
using namespace chrono;

template<typename T>
class GeneticAlgorithm {
public:
    GeneticAlgorithm(int popSize, double crossProb, double mutProb, KnapsackProblem<T> &problem);

    GeneticAlgorithm(GeneticAlgorithm<T> &algorithm);

    ~GeneticAlgorithm();

    Individual<T> *solveProblem(long timeInSeconds);

private:
    int popSize;
    double crossProb;
    double mutProb;
    int nOfItems;
    KnapsackProblem<T> *problem;
    Individual<T> *bestOfAll;

    vector<Individual<T> *> *generatePopulation();

    Individual<T> *generateIndividualsGenotype();

    void mutatePopulation(vector<Individual<T> *> *population);

    void crossPopulation(Individual<T> *fstParent, Individual<T> *sndParent, vector<Individual<T> *> *population);

    void destroyPopulation(vector<Individual<T> *> *population);

    Individual<T> *findTheBestFittingOne(vector<Individual<T> *> *population);

    Individual<T> *selectBetterFitting(Individual<T> *fst, Individual<T> *snd);

    Individual<T> *selectBetterFittingAndDeleteOther(Individual<T> *fst, Individual<T> *snd);

    Individual<T> *getRandomIndividual(vector<Individual<T> *> *population);

    bool doesActionAppear(double &probability);

};

template<typename T>
GeneticAlgorithm<T>::GeneticAlgorithm(int popSize, double crossProb, double mutProb, KnapsackProblem<T> &problem) {
    if (popSize <= 0)
        this->popSize = DEFAULT_POPSIZE;
    else
        this->popSize = popSize;

    if (crossProb <= 0 || crossProb > 1)
        this->crossProb = DEFAULT_CROSSPROB;
    else
        this->crossProb = crossProb;

    if (mutProb <= 0 || mutProb > 1)
        this->mutProb = DEFAULT_MUTPROB;
    else
        this->mutProb = mutProb;

    this->nOfItems = problem.getNOfItems();
    this->problem = &problem;
    this->bestOfAll = nullptr;
}

template<typename T>
GeneticAlgorithm<T>::GeneticAlgorithm(GeneticAlgorithm<T> &algorithm) {
    this->popSize = algorithm.popSize;
    this->crossProb = algorithm.crossProb;
    this->mutProb = algorithm.mutProb;
    this->nOfItems = algorithm.problem->getNOfItems();
    this->problem = algorithm.problem;
    this->bestOfAll = algorithm.bestOfAll;
}

template<typename T>
GeneticAlgorithm<T>::~GeneticAlgorithm() {
    delete bestOfAll;
};

template<typename T>
Individual<T> *GeneticAlgorithm<T>::solveProblem(long timeInSeconds) {
    vector<Individual<T> *> *population = generatePopulation();
    long timeFlow = 0;
    time_point<steady_clock> initialTime = steady_clock::now();
    if (timeInSeconds < 1) timeInSeconds = 1;
    int counter = 0;
    while (timeFlow < timeInSeconds) {

        vector<Individual<T> *> *nextGeneration = new vector<Individual<T> *>();
        while (nextGeneration->size() < popSize) {
            Individual<T> *fstParent = selectBetterFitting(getRandomIndividual(population),
                                                           getRandomIndividual(population));
            Individual<T> *sndParent = selectBetterFitting(getRandomIndividual(population),
                                                           getRandomIndividual(population));
            crossPopulation(fstParent, sndParent, nextGeneration);
        }
        mutatePopulation(nextGeneration);
        if (findTheBestFittingOne(population)->getFitness() >= findTheBestFittingOne(nextGeneration)->getFitness()) {
            destroyPopulation(nextGeneration);
        } else {
            destroyPopulation(population);
            population = nextGeneration;
        }
        /*  //TODO delete it, only to check how it works
          cout << "iteration: " << counter << " ||Best fitness: " << findTheBestFittingOne(population)->getFitness()
               << endl;*/
        timeFlow = duration_cast<seconds>(steady_clock::now() - initialTime).count();
        counter++;
    }
    bestOfAll = new Individual<T>(*findTheBestFittingOne(population));
    destroyPopulation(population);
    return bestOfAll;
}

template<typename T>
vector<Individual<T> *> *GeneticAlgorithm<T>::generatePopulation() {
    vector<Individual<T> *> *population = new vector<Individual<T> *>();
    for (int i = 0; i < popSize; ++i) {
        population->push_back(generateIndividualsGenotype());
    }
    return population;
}

template<typename T>
Individual<T> *GeneticAlgorithm<T>::generateIndividualsGenotype() {
    random_device rd;
    mt19937 gen(rd());
    T *generatedGenotype = new T[problem->getNOfItems()];

    for (int i = 0; i < problem->getNOfItems(); ++i) {
        uniform_real_distribution<> generate(-(problem->getMaxAmountOfItem().at(i) / 2),
                                             problem->getMaxAmountOfItem().at(i));
        T generatedFactor = (T) generate(gen);
        generatedFactor > T() ? generatedGenotype[i] = generatedFactor : generatedGenotype[i] = T();
    }
    return new Individual<T>(*problem, generatedGenotype, mutProb, crossProb);
}

template<typename T>
void GeneticAlgorithm<T>::crossPopulation(Individual<T> *fstParent, Individual<T> *sndParent,
                                          vector<Individual<T> *> *population) {
    if (doesActionAppear(crossProb)) { //cross parents and add their children to population
        Individual<T> *fstChild = *fstParent + *sndParent;
        Individual<T> *sndChild = *sndParent + *fstParent;

        if (population->size() + 1 < popSize) {
            population->push_back(fstChild);
            population->push_back(sndChild);
        } else {
            population->push_back(selectBetterFittingAndDeleteOther(fstChild, sndChild));
        }
    } else { // do not cross just add parents to new population
        if (population->size() + 1 < popSize) {
            population->push_back(new Individual<T>(*fstParent));
            population->push_back(new Individual<T>(*sndParent));
        } else {
            Individual<T> *betterFitting = (fstParent->getFitness() > sndParent->getFitness()) ? fstParent : sndParent;
            population->push_back(new Individual<T>(*betterFitting));
        }
    }
}

template<typename T>
void GeneticAlgorithm<T>::mutatePopulation(vector<Individual<T> *> *population) {
    for (Individual<T> *individual : *population) {
        //if (doesActionAppear(mutProb)) { //TODO gives better results, but doesn't fulfill specification requirements
        (*individual)++;
        //}
    }
}

template<typename T>
void GeneticAlgorithm<T>::destroyPopulation(vector<Individual<T> *> *population) {
    for (int i = 0; i < population->size(); ++i) {
        delete population->at(i);
    }
    delete population;
}

template<typename T>
Individual<T> *GeneticAlgorithm<T>::findTheBestFittingOne(vector<Individual<T> *> *population) {
    Individual<T> *bestIndividual = population->at(0);
    for (int i = 1; i < population->size(); ++i) {
        if (population->at(i)->getFitness() > bestIndividual->getFitness())
            bestIndividual = population->at(i);
    }
    return bestIndividual;
}

template<typename T>
Individual<T> *GeneticAlgorithm<T>::selectBetterFittingAndDeleteOther(Individual<T> *fst, Individual<T> *snd) {
    if (fst->getFitness() > snd->getFitness()) {
        delete snd;
        return fst;
    } else {
        delete fst;
        return snd;
    }
}

template<typename T>
Individual<T> *GeneticAlgorithm<T>::selectBetterFitting(Individual<T> *fst, Individual<T> *snd) {
    return (fst->getFitness() > snd->getFitness()) ? fst : snd;
}

template<typename T>
Individual<T> *GeneticAlgorithm<T>::getRandomIndividual(vector<Individual<T> *> *population) {
    return population->at((unsigned long) Tools::generateRandomNumber(0, (int) population->size() - 1));
}

template<typename T>
bool GeneticAlgorithm<T>::doesActionAppear(double &probability) {
    double randomProb = ((double) Tools::generateRandomNumber(0, 100) / 100.0);
    return randomProb < probability;
}


#endif //LIST_4_GENETICALGORITHM_H
