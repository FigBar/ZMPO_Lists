

#include <vector>
#include "Item.h"
#include "KnapsackProblem.h"

template<>
vector<Item *> *KnapsackProblem<bool>::decryptSolution(bool *genotype, int nOfGenes, double &decryptedWeight) {
    vector<Item *> *toDisplay = new vector<Item *>();

    for (int i = 0; i < nOfGenes; ++i) {
        if (genotype[i]) {
            toDisplay->push_back(itemList->at(i));
            toDisplay->back()->setPartTaken(1.0);
            decryptedWeight += itemList->at(i)->getWeight();
        }
    }
    return toDisplay;
}

template<>
void KnapsackProblem<bool>::countMaxAmount() {
    for (int i = 0; i < itemList->size(); ++i) {
        maxAmountOfItem.push_back(1);
    }
}