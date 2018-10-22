//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_CREATEMULTIPLETABLES_H
#define LIST_2_CREATEMULTIPLETABLES_H


#include "../Command.h"
#include "ListOneCommand.h"
#include<string>

using namespace std;

class createMultipleTables : public ListOneCommand {
public:
    createMultipleTables(TableHandler &handler);

    void runCommand();

    void addParametrizedSingleTable(string givenName, int givenLength);

    void addSingleTable();
};


#endif //LIST_2_CREATEMULTIPLETABLES_H
