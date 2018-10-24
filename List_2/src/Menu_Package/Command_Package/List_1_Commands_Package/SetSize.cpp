//
// Created by fig_bar98 on 21.10.18.
//

#include <climits>
#include <iostream>
#include "SetSize.h"
#include "../Utils.h"
#include "../../TableHandler_Package/TableHandler.h"

using namespace std;

SetSize::SetSize(TableHandler &handler) : ListOneCommand(handler) {

}

void SetSize::runCommand() {
    int index;
    if (!handler->getVector().empty()) {
        cout << MODIFIED_INDEX_REQUEST << endl;
        index = Utils::provideAnInt(0, handler->getVector().size() - 1);
        cout << NEW_LENGTH_REQUEST << endl;
        int newSize;
        newSize = Utils::provideInt(1, INT_MAX);

        if (changeSize(index, newSize)) {
            cout << OPERATION_SUCCESSED << endl;
        } else {
            cout << OPERATION_FAILED << endl;
        };
    } else {
        cout << EMPTY_LIST << endl;
    }
}

bool SetSize::changeSize(int index, int newSize) {
    if (index >= 0 && index < handler->getVector().size()) {
        return handler->getVector()[index]->setSize(newSize);
    } else return false;
}
