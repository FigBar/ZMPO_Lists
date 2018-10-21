//
// Created by fig_bar98 on 21.10.18.
//

#include <climits>
#include <iostream>
#include "SetSize.h"
#include "../Utils.h"
#include "../../TableHandler_Package/TableHandler.h"

using namespace std;

void SetSize::runCommand() {
    int index;
    if (!TableHandler::tableVector.empty()) {
        cout << "Please provide index of Table you want to modify" << endl;
        index = Utils::provideAnInt(0, TableHandler::tableVector.size() - 1);
        cout << "Now provide new length of chosen Table" << endl;
        int newSize;
        newSize = Utils::provideInt(1, INT_MAX);

        if (changeSize(index, newSize)) {
            cout << "Operation carried out successfully" << endl;
        } else {
            cout << "Operation failed, you provided invalid index or invalid table length :/" << endl;
        };
    } else {
        cout << "The list of Tables is empty" << endl;
    }
}

bool SetSize::changeSize(int index, int newSize) {
    if (index >= 0 && index < TableHandler::tableVector.size()) {
        return TableHandler::tableVector[index]->setSize(newSize);
    } else return false;
}
