//
// Created by fig_bar98 on 21.10.18.
//

#include <iostream>
#include "PrintAll.h"
#include "../../TableHandler_Package/TableHandler.h"

PrintAll::PrintAll(TableHandler &handler) : ListOneCommand(handler) {

}

void PrintAll::runCommand() {
    if (!handler->getVector().empty()) {
        cout << "------LIST_OF_TABLE_OBJECTS------" << endl;
        for (int i = 0; i < handler->getVector().size(); ++i) {
            cout << i << ". " << handler->getVector()[i]->toString() << endl;
        }
    } else {
        cout << "The list of Tables is empty" << endl << endl;
    }
}
