//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_PRINTALL_H
#define LIST_2_PRINTALL_H


#include "../Command.h"
#include "ListOneCommand.h"

class PrintAll : public ListOneCommand {
public:
    PrintAll(TableHandler &handler);
    void runCommand();
};


#endif //LIST_2_PRINTALL_H
