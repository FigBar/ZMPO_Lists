//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_DELETEONE_H
#define LIST_2_DELETEONE_H


#include "../Command.h"
#include "ListOneCommand.h"

class DeleteOne : public ListOneCommand {
public:
    DeleteOne(TableHandler &handler);
    void runCommand();
    void singleDelete();
    bool removeTable(int index);
};


#endif //LIST_2_DELETEONE_H
