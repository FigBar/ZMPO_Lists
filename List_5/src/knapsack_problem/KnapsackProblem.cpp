

#include <vector>
#include <tuple>
#include "Item.h"
#include "KnapsackProblem.h"

template<>
vector<tuple<Item*, bool>> *KnapsackProblem<bool>::decryptSolution(bool *genotype, int nOfGenes, double &decryptedWeight) {
    vector<tuple<Item*, bool>> *toDisplay = new vector<tuple<Item*, bool>>();

    for (int i = 0; i < nOfGenes; ++i) {
        if (genotype[i]) {
            toDisplay->push_back(make_tuple(itemList->at(i), genotype[i]));
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