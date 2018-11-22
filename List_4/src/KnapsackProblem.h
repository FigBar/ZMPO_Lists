//
// Created by fig_bar98 on 22.11.18.
//

#ifndef LIST_4_KNAPSACKPROBLEM_H
#define LIST_4_KNAPSACKPROBLEM_H

#include <vector>
#include "Item.h"

using namespace std;


class KnapsackProblem {
public:
    KnapsackProblem(vector<Item *> *list, double bagCap);

    int getNOfItems() const;

    double getBagCapacity() const;

    vector<Item *> *getItemList() const;

private:
    int nOfItems;
    double bagCapacity;
    vector<Item *> *itemList;
};


#endif //LIST_4_KNAPSACKPROBLEM_H
