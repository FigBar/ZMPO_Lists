//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_INSERTNUMBER_H
#define LIST_2_INSERTNUMBER_H


#include "../Command.h"

class InsertNumber : public Command {
public:
    virtual void runCommand();
    bool setValueInTable(int vectorIndex, int index, int newValue);
};


#endif //LIST_2_INSERTNUMBER_H
