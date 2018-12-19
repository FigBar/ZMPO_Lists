//
// Created by fig_bar98 on 15.12.18.
//

#ifndef LIST_5_DELETEITEMCOMMAND_H
#define LIST_5_DELETEITEMCOMMAND_H


#define DELETION_PROMPT "Please provide the index of item you want to remove: "

#include "../../lib/user_interface/Command.h"
#include "../knapsack_handler/KnapsackHandler.h"

class DeleteItemCommand : public Command {
public:
    DeleteItemCommand(KnapsackHandler *handler1);
    virtual void runCommand();

private:
    int getItemIndex();
    KnapsackHandler *handler;
};


#endif //LIST_5_DELETEITEMCOMMAND_H
