//
// Created by fig_bar98 on 06.10.18.
//

#include "CTable.h"
#include "iostream"

using namespace std;

CTable::CTable() : DEFAULT_SIZE(10), DEFAULT_NAME("Table1"){

    elem = new int[DEFAULT_SIZE];
    name = DEFAULT_NAME;
    size = DEFAULT_SIZE;

    cout <<"bezp: " << name << "\n";
}

CTable::CTable(string newName, int tableLength) : DEFAULT_SIZE(10), DEFAULT_NAME("Table1") {

    elem = new int[tableLength];
    name = newName;
    size = tableLength;

    cout << "parametr: " << name << "\n";

}

CTable& CTable::operator=(const CTable& copyOther) {

    int* p = new int[copyOther.size];

    for (int i = 0; i != copyOther.size ; ++i) {
        p[i] = copyOther.elem[i];
    }

    delete[] elem;
    elem = p;
    size = copyOther.size;

    return *this;
}

CTable::CTable(const CTable& copyOther) : DEFAULT_SIZE(10), DEFAULT_NAME("Table1") {

    elem = new int[copyOther.size];
    size = copyOther.size;
    name = copyOther.name + "_copy";

    for (int i = 0; i!=size; ++i){
        elem[i] = copyOther.elem[i];
    }

    cout << "kopiuj: " << name << "\n";

}

CTable::~CTable() {
    delete[] elem;

    cout << "usuwam: " << name << "\n";
}

int& CTable::operator[](int index) {
        return elem[index];

}

void CTable::setName(string newName) {
    CTable::name = newName;
}

void CTable::setSize(int newSize) {

    int* p = new int[newSize];

    for (int i = 0; i != this->size ; ++i) {
        p[i] = this->elem[i];
    }

    delete[] elem;
    elem = p;
    size = newSize;

}

int CTable::getSize() const {
    return size;
}

bool CTable::setVaule(int value, int index) {

    if(indexCheck(index)){
        elem[index] = value;
        return true;
    } else
        return false;
}

int CTable::getValue(int index, bool* opSuccess) {
    if(indexCheck(index)){
        *opSuccess = true;
        return elem[index];
    } else {
        *opSuccess = false;
        return -1;
    }
}

CTable CTable::clone() {
    return CTable(*this);
}

bool CTable::indexCheck(int index) {
    return (index >=0 && index < size);
}



