//
// Created by fig_bar98 on 21.10.18.
//
#include <iostream>
#include "PrintTable.h"
#include "../../TableHandler_Package/TableHandler.h"
#include "../Utils.h"

PrintTable::PrintTable(TableHandler &handler) : ListOneCommand(handler) {

}

void PrintTable::runCommand() {
    int index;
    if (!handler->getVector().empty()) {
        cout << "Please provide index of Table you want to get information about" << endl;
        index = Utils::provideAnInt(0, handler->getVector().size() - 1);
        if (index >= 0 && index < handler->getVector().size()) {
            cout << handler->getVector()[index]->toString() << endl;
        } else
            cout << "Operation failed, you provided invalid index :/" << endl;
    } else {
        cout << "The list of Tables is empty" << endl;
    }}
