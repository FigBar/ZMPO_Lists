//
// Created by fig_bar98 on 21.10.18.
//

#include "CloneTable.h"
#include "../../../../lib/utils/Utils.h"
#include <iostream>

CloneTable::CloneTable(TableHandler &handler) : ListOneCommand(handler) {}

void CloneTable::runCommand() {
    int index;
    if (!handler->getVector().empty()) {
        cout << CLONE_REQUEST << endl;
        index = Utils::provideAnInt(0, handler->getVector().size() - 1);
        if (appendClone(index)) {
            cout << OPERATION_SUCCESSED << endl;
        } else {
            cout << OPERATION_FAILED << endl;
        };
    } else {
        cout << EMPTY_LIST << endl;
    }
}

bool CloneTable::appendClone(int index) {
    if (index >= 0 && index < handler->getVector().size()) {
        handler->getVector().push_back(handler->getVector()[index]->clone());
        return true;
    } else return false;
}
