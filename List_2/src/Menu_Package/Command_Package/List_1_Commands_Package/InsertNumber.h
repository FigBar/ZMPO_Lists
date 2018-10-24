//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_INSERTNUMBER_H
#define LIST_2_INSERTNUMBER_H


#define PROVIDE_TABLE_INDEX "Please provide index of Table to which you want to assign a new value"

#define PROVIDE_NUMBER_INDEX "Now provide Table's index you want to assign to"

#define PROVIDE_NEW_VALUE "At final, please provide the value you want to assign"

#include "../Command.h"
#include "ListOneCommand.h"

class InsertNumber : public ListOneCommand {
public:
    InsertNumber(TableHandler &handler);
    virtual void runCommand();
    bool setValueInTable(int vectorIndex, int index, int newValue);
};


#endif //LIST_2_INSERTNUMBER_H
