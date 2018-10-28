//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_DELETEONE_H
#define LIST_2_DELETEONE_H


#define DELETION_INDEX_REQUEST "Please provide the number of Table object you want to remove."


#include "../ListOneCommand.h"

class DeleteOne : public ListOneCommand {
public:
    DeleteOne(TableHandler &handler);
    void runCommand();
    void singleDelete();
    bool removeTable(int index);
};


#endif //LIST_2_DELETEONE_H
