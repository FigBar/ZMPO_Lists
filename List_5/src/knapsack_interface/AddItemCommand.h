//
// Created by fig_bar98 on 15.12.18.
//

#ifndef LIST_5_ADDITEMCOMMAND_H
#define LIST_5_ADDITEMCOMMAND_H


#define NAME_OF_ITEM "Provide name of item: "

#define VALUE_OF_ITEM "Provide value of item: "

#define WEIGHT_OF_ITEM "Provide weight of item: "

#include "../../lib/user_interface/Command.h"
#include "../knapsack_handler/KnapsackHandler.h"

class AddItemCommand : public Command {
public:
    AddItemCommand(KnapsackHandler *handler1);
    virtual void runCommand();

private:
    Item *createItem();
    KnapsackHandler *handler;
};


#endif //LIST_5_ADDITEMCOMMAND_H
