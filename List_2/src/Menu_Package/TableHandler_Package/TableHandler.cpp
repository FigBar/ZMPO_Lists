//
// Created by Bartosz Figiel on 19.10.2018.
//

#include "TableHandler.h"
vector<Table*> TableHandler:: tableVector;

void TableHandler::destroyTableHandler() {
    for (int i = 0; i < tableVector.size() ; ++i) {
        delete tableVector[i];
    }
    tableVector.clear();
}
