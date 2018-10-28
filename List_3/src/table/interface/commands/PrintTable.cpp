//
// Created by fig_bar98 on 21.10.18.
//
#include <iostream>
#include "PrintTable.h"

#include "../../../../lib/utils/Utils.h"


PrintTable::PrintTable(TableHandler &handler) : ListOneCommand(handler) {

}

void PrintTable::runCommand() {
    int index;
    if (!handler->getVector().empty()) {
        cout << PROVIDE_PRINT_INDEX << endl;
        index = Utils::provideAnInt(0, handler->getVector().size() - 1);
        if (index >= 0 && index < handler->getVector().size()) {
            cout << handler->getVector()[index]->toString() << endl;
        } else
            cout << OPERATION_FAILED << endl;
    } else {
        cout << EMPTY_LIST << endl;
    }}
