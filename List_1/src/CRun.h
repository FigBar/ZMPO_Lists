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

    void menu();

    void addParametrizedSingleCTable(string givenName, int givenLength);

    void addSingleCTable();

    bool removeCTable(int index);

    bool changeSize(int index, int newSize);

    bool changeName(int index, string newName);

    bool appendClone(int index);

    bool setValueInCTable(int vectorIndex, int index, int newValue);

private:
    vector<CTable *> tableVector;
};


#endif //LIST_1_CRUN_H
