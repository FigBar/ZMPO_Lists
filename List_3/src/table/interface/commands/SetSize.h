//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_SETSIZE_H
#define LIST_2_SETSIZE_H


#define MODIFIED_INDEX_REQUEST "Please provide index of Table you want to modify"

#define NEW_LENGTH_REQUEST "Now provide new length of chosen Table"


#include "../ListOneCommand.h"

class SetSize : public ListOneCommand {
public:
    SetSize(TableHandler &handler);
    void runCommand();
    bool changeSize(int index, int newSize);
};


#endif //LIST_2_SETSIZE_H
