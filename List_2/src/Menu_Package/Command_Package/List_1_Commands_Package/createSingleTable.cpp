//
// Created by fig_bar98 on 21.10.18.
//

#include "createSingleTable.h"
#include "../Utils.h"
#include "../../../Table_Package/Table.h"
#include "../../TableHandler_Package/TableHandler.h"
#include <iostream>
#include <climits>

using namespace std;

void createSingleTable::runCommand() {
    if (Utils::yesOrNo()) {
        cout << "Now let's give your CTable a name." << endl;
        string givenName = Utils::provideString();

        cout << "Ok, what should be its length?" << endl;
        int givenInt = Utils::provideInt(0, INT_MAX);
        addParametrizedSingleTable(givenName, givenInt);

    } else {
        addSingleTable();
    }
}

void createSingleTable::addParametrizedSingleTable(string givenName, int givenLength) {
    Table *pointer;
    pointer = new Table(givenName, givenLength);
    TableHandler::tableVector.push_back(pointer);
}

void createSingleTable::addSingleTable() {
    Table *pointer;
    pointer = new Table();
    TableHandler::tableVector.push_back(pointer);
}
