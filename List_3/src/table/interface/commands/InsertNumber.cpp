//
// Created by fig_bar98 on 21.10.18.
//
#include <iostream>
#include <climits>
#include "InsertNumber.h"
#include "../../../../lib/utils/Utils.h"


InsertNumber::InsertNumber(TableHandler &handler) : ListOneCommand(handler) {

}

void InsertNumber::runCommand() {
    if (!handler->getVector().empty()) {
        int index;
        int vectorIndex;
        int value;
        cout << PROVIDE_TABLE_INDEX << endl;
        vectorIndex = Utils::provideAnInt(0, handler->getVector().size() - 1);
        cout << PROVIDE_NUMBER_INDEX << endl;
        index = Utils::provideAnInt(0, handler->getVector().at(vectorIndex)->getSize() - 1);
        cout << PROVIDE_NEW_VALUE << endl;
        value = Utils::provideInt(-INT_MAX, INT_MAX);

        if (setValueInTable(vectorIndex, index, value)) {
            cout << OPERATION_SUCCESSED << endl;
        } else {
            cout << OPERATION_FAILED << endl;
        };
    } else {
        cout << EMPTY_LIST << endl;
    }
}

bool InsertNumber::setValueInTable(int vectorIndex, int index, int newValue) {
    if (vectorIndex >= 0 && vectorIndex < handler->getVector().size()) {
        return handler->getVector()[vectorIndex]->setVaule(index, newValue);
    } else return false;
}

