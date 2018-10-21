//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_CREATESINGLETABLE_H
#define LIST_2_CREATESINGLETABLE_H


#include "../Command.h"
#include<string>

using namespace std;

class createSingleTable : public Command {
public:
    virtual void runCommand();

    void addParametrizedSingleTable(string givenName, int givenLength);

    void addSingleTable();
};


#endif //LIST_2_CREATESINGLETABLE_H
