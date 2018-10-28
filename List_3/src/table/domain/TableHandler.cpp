//
// Created by Bartosz Figiel on 19.10.2018.
//

#include "TableHandler.h"


 TableHandler::~TableHandler() {
    for (int i = 0; i < tableVector.size() ; ++i) {
        delete tableVector[i];
    }
    tableVector.clear();
}

vector<Table *> &TableHandler::getVector() {
    return tableVector;
}
