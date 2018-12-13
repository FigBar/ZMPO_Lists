//
// Created by fig_bar98 on 22.11.18.
//

#ifndef LIST_4_KNAPSACKPROBLEM_H
#define LIST_4_KNAPSACKPROBLEM_H

#define DEFAULT_BAG_CAPACITY 20

#include <vector>
#include "Item.h"

using namespace std;

template<typename T>
class KnapsackProblem {
public:
    KnapsackProblem(vector<Item *> &list, double bagCap);

    int getNOfItems() const;

    double getBagCapacity() const;

    vector<Item *> *getItemList() const;

    //TODO change calculating solutions weight to something more sophisticated xD
    vector<Item *> *decryptSolution(T *genotype, int nOfGenes, double &decryptedWeight);

    const vector<double> &getMaxAmountOfItem() const;


private:
    int nOfItems;
    double bagCapacity;
    vector<Item *> *itemList;
    vector<double> maxAmountOfItem;

    void countMaxAmount();
};

template<typename T>
KnapsackProblem<T>::KnapsackProblem(vector<Item *> &list, double bagCap) {
    if (bagCap <= 0)
        this->bagCapacity = DEFAULT_BAG_CAPACITY;
    else
        this->bagCapacity = bagCap;
    this->nOfItems = (int) list.size();
    this->itemList = &list;
    countMaxAmount();
}

template<typename T>
vector<Item *> *KnapsackProblem<T>::decryptSolution(T *genotype, int nOfGenes, double &decryptedWeight) {
    vector<Item *> *toDisplay = new vector<Item *>();

    for (int i = 0; i < nOfGenes; ++i) {
        if (genotype[i] != T()) {
            toDisplay->push_back(itemList->at(i));
            toDisplay->back()->setPartTaken((double)genotype[i]);
            decryptedWeight += (double)(genotype[i] * itemList->at(i)->getWeight());
        }
    }
    return toDisplay;
}

template<> inline
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

template<typename T>
void KnapsackProblem<T>::countMaxAmount() {
    for (int i = 0; i < itemList->size(); ++i) {
        double weight = itemList->at(i)->getWeight();
        maxAmountOfItem.push_back(bagCapacity / weight);
    }
}

template<> inline
void KnapsackProblem<bool>::countMaxAmount() {
    for (int i = 0; i < itemList->size(); ++i) {
        maxAmountOfItem.push_back(1);
    }
}

template<typename T>
int KnapsackProblem<T>::getNOfItems() const {
    return nOfItems;
}

template<typename T>
double KnapsackProblem<T>::getBagCapacity() const {
    return bagCapacity;
}

template<typename T>
vector<Item *> *KnapsackProblem<T>::getItemList() const {
    return itemList;
}

template<typename T>
const vector<double> &KnapsackProblem<T>::getMaxAmountOfItem() const {
    return maxAmountOfItem;
}


#endif //LIST_4_KNAPSACKPROBLEM_H