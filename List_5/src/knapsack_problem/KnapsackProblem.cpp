//
// Created by fig_bar98 on 22.11.18.
//

#include "KnapsackProblem.h"
/*
template <typename T>
KnapsackProblem<T>::KnapsackProblem(vector<Item *> &list, double bagCap) {
    if(bagCap <= 0)
        this->bagCapacity = DEFAULT_BAG_CAPACITY;
    else
        this->bagCapacity = bagCap;
    this->nOfItems = (int)list.size();
    this->itemList = &list;
}
template <typename T>
vector<Item *> *KnapsackProblem<T>::decryptSolution(int *genotype, int nOfGenes) {
    vector<Item *> *toDisplay = new vector<Item*>();

    for (int i = 0; i < nOfGenes; ++i) {
        if(genotype[i] == 1)
            toDisplay->push_back(itemList->at(i));
    }
    return toDisplay;
}

template<typename T>
void KnapsackProblem<T>::countMaxAmount() {
    for(Item *item : itemList){
        double weight = item->getWeight();
        maxAmountOfItem.push_back(bagCapacity/weight);
    }
}

template <>
void KnapsackProblem<bool>::countMaxAmount() {
    for (int i = 0; i < itemList->size() ; ++i) {
        maxAmountOfItem.push_back(1);
    }
}

template <typename T>
int KnapsackProblem<T>::getNOfItems() const {
    return nOfItems;
}
template <typename T>
double KnapsackProblem<T>::getBagCapacity() const {
    return bagCapacity;
}
template <typename T>
vector<Item *> *KnapsackProblem<T>::getItemList() const {
    return itemList;
}
*/
