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

    ~CRun();

    void start();

    void addParametrizedSingleCTable(string givenName, int givenLength);

    void addSingleCTable();

    bool yesOrNo();

    string provideString();

    int provideInt();

private:
    vector<CTable *> tableVector;
    //bool *success;
};


#endif //LIST_1_CRUN_H
