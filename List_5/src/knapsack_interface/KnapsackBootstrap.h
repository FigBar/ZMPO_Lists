//
// Created by fig_bar98 on 13.12.18.
//

#ifndef LIST_5_KNAPSACKBOOTSTRAP_H
#define LIST_5_KNAPSACKBOOTSTRAP_H


#define MAIN_MENU "Main Menu"

#define MAIN_COMMAND "main"

#define BOOL_NAME "Solve boolean knapsack problem"

#define BOOL_COMMAND "bool"

#define INTEGER_NAME "Solve integer knapsack problem"

#define INTEGER_COMMAND "int"

#define DOUBLE_NAME "Solve double knapsack problem"

#define PRINT_ITEMS_NAME "Print list of problem's items"

#define PRINT_ITEMS_COMMAND "print"

#define ADD_ITEM_NAME "Add item to problem"

#define ADD_ITEM_COMMAND "add"

#define DELETE_ITEM_NAME "Delete item from problem"

#define DELETE_ITEM_COMMAND "delete"

#include "../../lib/user_interface/Menu.h"
#include "../knapsack_problem/Item.h"
#include "../knapsack_handler/KnapsackHandler.h"

class KnapsackBootstrap {

public:
    static Menu* initializeKnapsackMenu(KnapsackHandler *handler);
};


#endif //LIST_5_KNAPSACKBOOTSTRAP_H
