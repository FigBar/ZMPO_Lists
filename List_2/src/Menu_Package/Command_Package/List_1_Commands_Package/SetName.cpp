//
// Created by fig_bar98 on 21.10.18.
//
#include <iostream>
#include "SetName.h"
#include "../../TableHandler_Package/TableHandler.h"
#include "../Utils.h"

using namespace std;

SetName::SetName(TableHandler &handler) : ListOneCommand(handler) {

}

void SetName::runCommand() {
    int index;
    if (!handler->getVector().empty()) {
        cout << MODIFIED_INDEX_REQUEST << endl;
        index = Utils::provideAnInt(0, handler->getVector().size() - 1);
        cout << NEW_NAME_REQUEST << endl;
        if (changeName(index, Utils::provideString())) {
            cout << OPERATION_SUCCESSED << endl;
        } else {
            cout << OPERATION_FAILED << endl;
        };
    } else {
        cout << EMPTY_LIST << endl;
    }
}

bool SetName::changeName(int index, string newName) {
    if (index >= 0 && index < handler->getVector().size()) {
        handler->getVector()[index]->setName(newName);
        return true;
    } else return false;
}
