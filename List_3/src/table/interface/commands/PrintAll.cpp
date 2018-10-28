//
// Created by fig_bar98 on 21.10.18.
//

#include <iostream>
#include "PrintAll.h"

PrintAll::PrintAll(TableHandler &handler) : ListOneCommand(handler) {

}

void PrintAll::runCommand() {
    if (!handler->getVector().empty()) {
        cout << LIST_HEADER << endl;
        for (int i = 0; i < handler->getVector().size(); ++i) {
            cout << i << ". " << handler->getVector()[i]->toString() << endl;
        }
    } else {
        cout << EMPTY_LIST << endl << endl;
    }
}
