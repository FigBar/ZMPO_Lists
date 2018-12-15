//
// Created by fig_bar98 on 15.12.18.
//

#ifndef LIST_5_PRINTPROBLEMCOMMAND_H
#define LIST_5_PRINTPROBLEMCOMMAND_H


#include "../../lib/user_interface/Command.h"
#include "../knapsack_handler/KnapsackHandler.h"

class PrintProblemCommand : public Command{
public:
    PrintProblemCommand(KnapsackHandler *handler1);
    virtual void runCommand();
private:
    KnapsackHandler *handler;
};


#endif //LIST_5_PRINTPROBLEMCOMMAND_H
