//
// Created by fig_bar98 on 21.10.18.
//

#include <iostream>
#include "PrintAll.h"
#include "../../TableHandler_Package/TableHandler.h"

void PrintAll::runCommand() {
    if (!TableHandler::tableVector.empty()) {
        cout << "------LIST_OF_TABLE_OBJECTS------" << endl;
        for (int i = 0; i < TableHandler::tableVector.size(); ++i) {
            cout << i << ". " << TableHandler::tableVector[i]->toString() << endl;
        }
    } else {
        cout << "The list of Tables is empty" << endl << endl;
    }
}
