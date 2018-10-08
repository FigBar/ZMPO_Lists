//
// Created by fig_bar98 on 07.10.18.
//

#ifndef LIST_1_CRUN_H
#define LIST_1_CRUN_H

#include "vector"
#include "CTable.h"
using namespace std;

class CRun {

public:

    CRun();

   void addToVector(int numberOfElements);

private:
    vector<CTable*> tableVector;
};


#endif //LIST_1_CRUN_H
