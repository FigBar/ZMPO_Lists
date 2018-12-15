//
// Created by fig_bar98 on 13.12.18.
//

#ifndef LIST_5_KNAPSACKBOOTSTRAP_H
#define LIST_5_KNAPSACKBOOTSTRAP_H


#include "../../lib/user_interface/Menu.h"
#include "../knapsack_problem/Item.h"
#include "../knapsack_handler/KnapsackHandler.h"

class KnapsackBootstrap {

public:
    static Menu* initializeKnapsackMenu(KnapsackHandler *handler);
};


#endif //LIST_5_KNAPSACKBOOTSTRAP_H
