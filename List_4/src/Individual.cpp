//
// Created by fig_bar98 on 22.11.18.
//
#include <random>
#include "Individual.h"
#include "utils/Tools.h"

Individual::Individual(KnapsackProblem &instOfProblem) {
    this->problem = &instOfProblem;
    this->nOfGenes = instOfProblem.getNOfItems();
    this->genotype = new int[nOfGenes];
    calcFitness();
}

Individual::Individual(KnapsackProblem &instOfProblem, int *genotype) {
    this->problem = &instOfProblem;
    this->nOfGenes = instOfProblem.getNOfItems();
    this->genotype = genotype;
    calcFitness();
}

Individual::Individual(Individual &copyOther) {
    this->problem = copyOther.problem;
    this->nOfGenes = copyOther.nOfGenes;
    this->genotype = new int[nOfGenes];

    for (int i = 0; i < nOfGenes; ++i) {
        genotype[i] = copyOther.genotype[i];
    }
    calcFitness();
}

Individual::~Individual() {
    delete[] genotype;
}

void Individual::calcFitness() {
    double weightSum = 0;
    double valueSum = 0;
    double bagCapacity = problem->getBagCapacity();
    vector<Item *> *listOfItems = problem->getItemList();

    for (int i = 0; i < nOfGenes; ++i) {
        if (genotype[i] == 1) {
            Item *current = (*listOfItems)[i];
            weightSum += current->getWeight();
            valueSum += current->getValue();
        }
    }
    this->fitness = (weightSum <= bagCapacity) ? valueSum : 0;
}

void Individual::mutate(int index) {
    if (genotype[index] == 1)
        genotype[index] = 0;
    else
        genotype[index] = 1;
    calcFitness();
}


vector<Individual *> *Individual::cross(Individual &crossWith) {
    vector<Individual *> *offspring = new vector<Individual *>;

    int crossingIndex = Tools::generateRandomNumber(1, nOfGenes - 1);

    int *fstDescendantGenotype = new int[nOfGenes];
    int *sndDescendantGenotype = new int[nOfGenes];

    for (int i = 0; i < crossingIndex; ++i) {
        fstDescendantGenotype[i] = this->genotype[i];
        sndDescendantGenotype[i] = crossWith.genotype[i];
    }
    for (int j = crossingIndex; j < nOfGenes; ++j) {
        fstDescendantGenotype[j] = crossWith.genotype[j];
        sndDescendantGenotype[j] = this->genotype[j];
    }

    Individual *fstDescendant = new Individual(*(this->problem), fstDescendantGenotype);
    Individual *sndDescendant = new Individual(*(this->problem), sndDescendantGenotype);

    offspring->push_back(fstDescendant);
    offspring->push_back(sndDescendant);

    return offspring;
}

double Individual::getFitness() const {
    return fitness;
}

int *Individual::getGenotype() const {
    return genotype;
}

int Individual::getNOfGenes() const {
    return nOfGenes;
}
