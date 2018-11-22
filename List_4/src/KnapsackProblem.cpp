//
// Created by fig_bar98 on 22.11.18.
//

#include "KnapsackProblem.h"

KnapsackProblem::KnapsackProblem(vector<Item *> *list, double bagCap) {
    this->bagCapacity = bagCap;
    this->nOfItems = (int)list->size();
    this->itemList = list;
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
