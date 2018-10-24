//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_DELETEALL_H
#define LIST_2_DELETEALL_H


#define DELETION_EMPTY_LIST "There's nothing to delete"

#include "../Command.h"
#include "ListOneCommand.h"

class DeleteAll : public ListOneCommand{
public:
    DeleteAll(TableHandler &handler);
    void runCommand();
    void deleteAll();
};


#endif //LIST_2_DELETEALL_H
