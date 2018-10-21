//
// Created by fig_bar98 on 21.10.18.
//
#include <iostream>
#include "SetName.h"
#include "../../TableHandler_Package/TableHandler.h"
#include "../Utils.h"

using namespace std;

void SetName::runCommand() {
    int index;
    if (!TableHandler::tableVector.empty()) {
        cout << "Please provide index of Table you want to modify" << endl;
        index = Utils::provideAnInt(0, TableHandler::tableVector.size() - 1);
        cout << "Please provide new name of chosen Table" << endl;
        if (changeName(index, Utils::provideString())) {
            cout << "Operation carried out successfully" << endl;
        } else {
            cout << "Operation failed, you provided invalid index :/" << endl;
        };
    } else {
        cout << "The list of Tables is empty" << endl;
    }
}

bool SetName::changeName(int index, string newName) {
    if (index >= 0 && index < TableHandler::tableVector.size()) {
        TableHandler::tableVector[index]->setName(newName);
        return true;
    } else return false;
}
