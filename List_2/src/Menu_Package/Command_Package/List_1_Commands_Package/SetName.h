//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_SETNAME_H
#define LIST_2_SETNAME_H


#include "../Command.h"
#include "ListOneCommand.h"
#include <string>
using namespace std;

class SetName : public ListOneCommand {
public:
    SetName(TableHandler &handler);
    void runCommand();
    bool changeName(int index, string newName);
};


#endif //LIST_2_SETNAME_H
