//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_CREATEMULTIPLETABLES_H
#define LIST_2_CREATEMULTIPLETABLES_H

#define AMOUNT_REQUEST "How many Table object do you want to create?"
#define NAME_REQUEST "Now let's give your Table a name."
#define LENGTH_REQUEST "Ok, what should be its length?"

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
