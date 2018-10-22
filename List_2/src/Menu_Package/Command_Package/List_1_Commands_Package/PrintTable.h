//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_PRINTTABLE_H
#define LIST_2_PRINTTABLE_H


#include "../Command.h"
#include "ListOneCommand.h"

class PrintTable : public ListOneCommand {
public:
    PrintTable(TableHandler &handler);
    void runCommand();
};


#endif //LIST_2_PRINTTABLE_H
