//
// Created by fig_bar98 on 21.10.18.
//
#include <iostream>
#include <climits>
#include "InsertNumber.h"
#include "../../TableHandler_Package/TableHandler.h"
#include "../Utils.h"

InsertNumber::InsertNumber(TableHandler &handler) : ListOneCommand(handler) {

}

void InsertNumber::runCommand() {
    if (!handler->getVector().empty()) {
        int index;
        int vectorIndex;
        int value;
        cout << "Please provide index of Table to which you want to assign a new value" << endl;
        vectorIndex = Utils::provideAnInt(0, handler->getVector().size() - 1);
        cout << "Now provide Table's index you want to assign to" << endl;
        index = Utils::provideAnInt(0, handler->getVector().at(vectorIndex)->getSize() - 1);
        cout << "At final, please provide the value you want to assign" << endl;
        value = Utils::provideInt(-INT_MAX, INT_MAX);

        if (setValueInTable(vectorIndex, index, value)) {
            cout << "Operation carried out successfully" << endl;
        } else {
            cout << "Operation failed, you provided invalid index :/" << endl;
        };
    } else {
        cout << "The list of Tables is empty" << endl;
    }
}

bool InsertNumber::setValueInTable(int vectorIndex, int index, int newValue) {
    if (vectorIndex >= 0 && vectorIndex < handler->getVector().size()) {
        return handler->getVector()[vectorIndex]->setVaule(index, newValue);
    } else return false;
}

