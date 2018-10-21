//
// Created by fig_bar98 on 21.10.18.
//

#include "CloneTable.h"
#include "../../TableHandler_Package/TableHandler.h"
#include "../Utils.h"
#include <iostream>

void CloneTable::runCommand() {
    int index;
    if (!TableHandler::tableVector.empty()) {
        cout << "Please provide index of Table you want to clone" << endl;
        index = Utils::provideAnInt(0, TableHandler::tableVector.size() - 1);
        if (appendClone(index)) {
            cout << "Operation carried out successfully" << endl;
        } else {
            cout << "Operation failed, you provided invalid index :/" << endl;
        };
    } else {
        cout << "The list of Tables is empty" << endl;
    }
}

bool CloneTable::appendClone(int index) {
    if (index >= 0 && index < TableHandler::tableVector.size()) {
        TableHandler::tableVector.push_back(TableHandler::tableVector[index]->clone());
        return true;
    } else return false;
}
