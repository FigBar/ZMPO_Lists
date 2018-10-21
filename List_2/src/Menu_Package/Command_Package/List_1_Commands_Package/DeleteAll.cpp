//
// Created by fig_bar98 on 21.10.18.
//

#include "DeleteAll.h"
#include "../../TableHandler_Package/TableHandler.h"
#include <iostream>
using namespace std;

void DeleteAll::runCommand() {
    deleteAll();
}

void DeleteAll::deleteAll() {
    if (TableHandler::tableVector.empty())
        cout << "There's nothing to delete" << endl;

    for (int i = 0; i < TableHandler::tableVector.size(); ++i) {
        delete TableHandler::tableVector[i];
    }
    TableHandler::tableVector.clear();
}
