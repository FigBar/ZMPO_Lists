//
// Created by fig_bar98 on 21.10.18.
//

#include "createMultipleTables.h"
#include "../../../../lib/utils/Utils.h"
#include <iostream>
#include <climits>

createMultipleTables::createMultipleTables(TableHandler &handler) : ListOneCommand(handler){}

void createMultipleTables::runCommand() {
    int amount;
    cout << AMOUNT_REQUEST << endl;
    amount = Utils::provideInt(0, INT_MAX);
    if (Utils::yesOrNo()) {
        for (int i = 0; i < amount; ++i) {
            cout << NAME_REQUEST << "\n";
            string givenName = Utils::provideString();
            cout << LENGTH_REQUEST << endl;
            int givenInt = Utils::provideInt(0, INT_MAX);
            addParametrizedSingleTable(givenName, givenInt);
        }
    } else {
        for (int i = 0; i < amount; ++i) {
            addSingleTable();
        }
    }
}

void createMultipleTables::addParametrizedSingleTable(string givenName, int givenLength) {
    Table *pointer;
    pointer = new Table(givenName, givenLength);
    handler->getVector().push_back(pointer);
}

void createMultipleTables::addSingleTable() {
    Table *pointer;
    pointer = new Table();
    handler->getVector().push_back(pointer);
}
