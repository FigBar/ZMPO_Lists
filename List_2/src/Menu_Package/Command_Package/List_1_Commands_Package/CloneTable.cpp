//
// Created by fig_bar98 on 21.10.18.
//

#include "CloneTable.h"
#include "../../TableHandler_Package/TableHandler.h"
#include "../Utils.h"
#include <iostream>

CloneTable::CloneTable(TableHandler &handler) : ListOneCommand(handler) {}

void CloneTable::runCommand() {
    int index;
    if (!handler->getVector().empty()) {
        cout << "Please provide index of Table you want to clone" << endl;
        index = Utils::provideAnInt(0, handler->getVector().size() - 1);
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
    if (index >= 0 && index < handler->getVector().size()) {
        handler->getVector().push_back(handler->getVector()[index]->clone());
        return true;
    } else return false;
}
