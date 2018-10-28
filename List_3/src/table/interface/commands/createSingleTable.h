//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_CREATESINGLETABLE_H
#define LIST_2_CREATESINGLETABLE_H


#define NAME_REQUEST "Now let's give your Table a name."

#define LENGTH_REQUEST "Ok, what should be its length?"


#include<string>
#include "../ListOneCommand.h"

using namespace std;

class createSingleTable : public ListOneCommand {
public:
    createSingleTable(TableHandler &handler);

    void runCommand();

    void addParametrizedSingleTable(string givenName, int givenLength);

    void addSingleTable();
};


#endif //LIST_2_CREATESINGLETABLE_H
