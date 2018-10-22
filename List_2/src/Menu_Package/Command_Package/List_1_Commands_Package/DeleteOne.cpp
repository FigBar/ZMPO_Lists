//
// Created by fig_bar98 on 21.10.18.
//
#include <iostream>
#include "DeleteOne.h"
#include "../../TableHandler_Package/TableHandler.h"
#include "../Utils.h"

DeleteOne::DeleteOne(TableHandler &handler) : ListOneCommand(handler) {

}

void DeleteOne::runCommand() {
    singleDelete();
}

void DeleteOne::singleDelete() {
    int index;
    if (!handler->getVector().empty()) {
        cout << "Please provide the number of Table object you want to remove." << endl;
        index = Utils::provideAnInt(0, handler->getVector().size() - 1);
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
    if (index >= 0 && index < handler->getVector().size()) {
        delete handler->getVector().at(index);
        handler->getVector().erase(handler->getVector().begin() + index);
        return true;
    } else return false;
}
