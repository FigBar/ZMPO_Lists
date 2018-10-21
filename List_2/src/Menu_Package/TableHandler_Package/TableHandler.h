//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_TABLEHANDLER_H
#define LIST_2_TABLEHANDLER_H

#include<vector>
#include "../../Table_Package/Table.h"

using namespace std;

class TableHandler {

public:
    static void destroyTableHandler();

    static vector<Table*> tableVector;
};


#endif //LIST_2_TABLEHANDLER_H
