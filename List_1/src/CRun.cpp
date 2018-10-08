//
// Created by fig_bar98 on 07.10.18.
//

#include "CRun.h"
#include "CTable.h"
#include <vector>

CRun::CRun() {

}

void CRun::addToVector(int numberOfElements) {

    CTable* p;
    for (int i = 0; i < numberOfElements-1 ; ++i) {
        p = new CTable();
        tableVector.push_back(p);
    }
    delete p;
}