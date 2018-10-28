//
// Created by fig_bar98 on 21.10.18.
//
#include <iostream>
#include "DeleteOne.h"
#include "../../../../lib/utils/Utils.h"


DeleteOne::DeleteOne(TableHandler &handler) : ListOneCommand(handler) {

}

void DeleteOne::runCommand() {
    singleDelete();
}

void DeleteOne::singleDelete() {
    int index;
    if (!handler->getVector().empty()) {
        cout << DELETION_INDEX_REQUEST << endl;
        index = Utils::provideAnInt(0, handler->getVector().size() - 1);
        if (removeTable(index)) {
            cout << OPERATION_SUCCESSED << endl;
        } else {
            cout << OPERATION_FAILED << endl;
        };
    } else {
        cout << EMPTY_LIST << endl;
    }
}

bool DeleteOne::removeTable(int index) {
    if (index >= 0 && index < handler->getVector().size()) {
        delete handler->getVector().at(index);
        handler->getVector().erase(handler->getVector().begin() + index);
        return true;
    } else return false;
}
