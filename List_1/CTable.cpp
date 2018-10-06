//
// Created by fig_bar98 on 06.10.18.
//

#include "CTable.h"
#include "iostream"

using namespace std;

CTable::CTable() {

    elem = new int[DEFAULT_SIZE];
    name = DEFAULT_NAME;
    size = DEFAULT_SIZE;

    cout <<"bezp: " << name << "\n";
}

CTable::CTable(string newName, int tableLength) {

    elem = new int[tableLength];
    name = newName;
    size = tableLength;

    cout << "parametr: " << name << "\n";

}

CTable& CTable::operator=(const CTable &copyOther) {

    int* p = new int[copyOther.size];

    for (int i = 0; i != copyOther.size ; ++i) {
        p[i] = copyOther.elem[i];
    }

    delete[] elem;
    elem = p;
    size = copyOther.size;

    return *this;
}

CTable::CTable(const CTable& copyOther) {

    elem = new int[copyOther.size];
    size = copyOther.size;
    name = copyOther.name + "_copy";

    for (int i = 0; i!=size; ++i){
        elem[i] = copyOther.elem[i];
    }



}

CTable::~CTable() {
    delete[] elem;
}

int& CTable::operator[](int index) {
    return elem[index];
}

void CTable::setName(string newName) {
    CTable::name = newName;
}

int CTable::getSize() const {
    return size;
}



