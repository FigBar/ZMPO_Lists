//
// Created by fig_bar98 on 21.10.18.
//
#include <iostream>
#include "DeleteOne.h"
#include "../../TableHandler_Package/TableHandler.h"
#include "../Utils.h"

void DeleteOne::runCommand() {
    singleDelete();
}

void DeleteOne::singleDelete() {
    int index;
    if (!TableHandler::tableVector.empty()) {
        cout << "Please provide the number of Table object you want to remove." << endl;
        index = Utils::provideAnInt(0, TableHandler::tableVector.size() - 1);
        if (removeTable(index)) {
            cout << "Operation carried out successfully" << endl;
        } else {
            cout << "Operation failed, you provided invalid index :/" << endl;
        };
    } else {
        cout << "There's nothing to remove." << endl;
    }
}

bool DeleteOne::removeTable(int index) {
    if (index >= 0 && index < TableHandler::tableVector.size()) {
        delete TableHandler::tableVector.at(index);
        TableHandler::tableVector.erase(TableHandler::tableVector.begin() + index);
        return true;
    } else return false;
}
