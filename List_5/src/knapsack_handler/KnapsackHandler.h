//
// Created by fig_bar98 on 15.12.18.
//

#ifndef LIST_5_KNAPSACKHANDLER_H
#define LIST_5_KNAPSACKHANDLER_H

#include <vector>
#include "../knapsack_problem/Item.h"

using namespace std;

class KnapsackHandler {
public:
    KnapsackHandler();

    KnapsackHandler(vector<Item *> *itemsList);

    ~KnapsackHandler();

    void addItem(Item *newItem);

    void deleteItem(int index);

    void deleteAllItems();

    vector<Item *> *getItems();

    void printItems();

private:
    vector<Item *> *itemsList;
};


#endif //LIST_5_KNAPSACKHANDLER_H
