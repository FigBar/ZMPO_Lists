//
// Created by fig_bar98 on 21.10.18.
//

#include "createSingleTable.h"
#include "../../../../lib/utils/Utils.h"

#include <iostream>
#include <climits>

using namespace std;

createSingleTable::createSingleTable(TableHandler &handler) : ListOneCommand(handler) {

}

void createSingleTable::runCommand() {
    if (Utils::yesOrNo()) {
        cout << NAME_REQUEST << endl;
        string givenName = Utils::provideString();

        cout << LENGTH_REQUEST << endl;
        int givenInt = Utils::provideInt(0, INT_MAX);
        addParametrizedSingleTable(givenName, givenInt);

    } else {
        addSingleTable();
    }
}

void createSingleTable::addParametrizedSingleTable(string givenName, int givenLength) {
    Table *pointer;
    pointer = new Table(givenName, givenLength);
    handler->getVector().push_back(pointer);
}

void createSingleTable::addSingleTable() {
    Table *pointer;
    pointer = new Table();
    handler->getVector().push_back(pointer);
}
