//
// Created by fig_bar98 on 22.11.18.
//
#include <random>
#include "Individual.h"

Individual::Individual(KnapsackProblem &instOfProblem) {
    this->problem = &instOfProblem;
    this->nOfGenes = (int) instOfProblem.getItemList()->size();
    this->genotype = new int[nOfGenes];
    generateGenotype();
    calcFitness();
}

Individual::Individual(const Individual &copyOther) {
    this->problem = copyOther.problem;
    this->nOfGenes = copyOther.nOfGenes;
    this->genotype = new int[nOfGenes];
    int *copiedGenotype = copyOther.genotype;
    for (int i = 0; i < nOfGenes; ++i) {
        genotype[i] = copiedGenotype[i];
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
            Item *current = listOfItems->[i];
            weightSum += current->getWeight();
            valueSum += current->getValue();
        }
    }

    fitness = (weightSum <= bagCapacity) ? valueSum : 0;

}

void Individual::mutate(const double &mutProb) {

}

void Individual::generateGenotype() {
    for (int i = 0; i < nOfGenes; ++i)
        genotype[i] = generateRandomNumber(0, 1);

}

int Individual::generateRandomNumber(int lowerBound, int upperBound) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> generate(lowerBound, upperBound);
    return generate(gen);
}

vector<Individual *> Individual::cross(Individual &crossWith) {
    return vector<Individual *>();
}
