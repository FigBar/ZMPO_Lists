#include "Individual.h"

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

template<>
void Individual<bool>::mutate() {
    for (int i = 0; i < nOfGenes; ++i) {
        if (((double) Tools::generateRandomNumber(0, 100) / 100.0) < mutProb) {
            genotype[i] = !genotype[i];
        }
    }
    calcFitness();
}