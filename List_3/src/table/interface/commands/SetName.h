//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_SETNAME_H
#define LIST_2_SETNAME_H


#define NEW_NAME_REQUEST "Please provide new name of chosen Table"

#define MODIFIED_INDEX_REQUEST "Please provide index of Table you want to modify"


#include "../ListOneCommand.h"
#include <string>
using namespace std;

class SetName : public ListOneCommand {
public:
    SetName(TableHandler &handler);
    void runCommand();
    bool changeName(int index, string newName);
};


#endif //LIST_2_SETNAME_H
