//
// Created by fig_bar98 on 22.11.18.
//

#include "KnapsackProblem.h"

int KnapsackProblem::getNOfItems() const {
    return nOfItems;
}

double KnapsackProblem::getBagCapacity() const {
    return bagCapacity;
}

vector<Item *> *KnapsackProblem::getItemList() const {
    return itemList;
}
