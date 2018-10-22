//
// Created by fig_bar98 on 21.10.18.
//

#include "DeleteAll.h"
#include "../../TableHandler_Package/TableHandler.h"
#include <iostream>
using namespace std;

DeleteAll::DeleteAll(TableHandler &handler) : ListOneCommand(handler) {

}

void DeleteAll::runCommand() {
    deleteAll();
}

void DeleteAll::deleteAll() {
    if (handler->getVector().empty())
        cout << "There's nothing to delete" << endl;

    for (int i = 0; i < handler->getVector().size(); ++i) {
        delete handler->getVector()[i];
    }
    handler->getVector().clear();
}
