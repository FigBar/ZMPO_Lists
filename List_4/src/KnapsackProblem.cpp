//
// Created by fig_bar98 on 22.11.18.
//

#include "KnapsackProblem.h"

KnapsackProblem::KnapsackProblem(vector<Item *> &list, double bagCap) {
    this->bagCapacity = bagCap;
    this->nOfItems = (int)list.size();
    this->itemList = &list;
}

vector<Item *> *KnapsackProblem::decryptSolution(int *genotype, int nOfGenes) {
    vector<Item *> *toDisplay = new vector<Item*>();

    for (int i = 0; i < nOfGenes; ++i) {
        if(genotype[i] == 1)
            toDisplay->push_back(itemList->at(i));
    }
    return toDisplay;
}

int KnapsackProblem::getNOfItems() const {
    return nOfItems;
}

double KnapsackProblem::getBagCapacity() const {
    return bagCapacity;
}

vector<Item *> *KnapsackProblem::getItemList() const {
    return itemList;
}
