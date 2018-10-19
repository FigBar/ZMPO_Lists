//
// Created by Bartosz Figiel on 19.10.2018.
//

#include "Table.h"
#include "iostream"
#include "sstream"
#include "Tools.h"

using namespace std;

/*
 * Constructors
 */
Table::Table() : DEFAULT_SIZE(10), DEFAULT_NAME("Table1") {

    elem = new int[DEFAULT_SIZE];
    name = DEFAULT_NAME;
    size = DEFAULT_SIZE;
    Tools::initializeWithZeros(elem, 0, size);

    cout << "bezp: " << name << "\n";
}

Table::Table(string newName, int tableLength) : DEFAULT_SIZE(10), DEFAULT_NAME("Table1") {

    elem = new int[tableLength];
    name = newName;
    size = tableLength;
    Tools::initializeWithZeros(elem, 0, size);

    cout << "parametr: " << name << "\n";

}

Table::Table(const Table &copyOther) : DEFAULT_SIZE(10), DEFAULT_NAME("Table1") {

    elem = new int[copyOther.size];
    size = copyOther.size;
    name = copyOther.name + "_copy";

    for (int i = 0; i != size; ++i) {
        *(elem + i) = *(copyOther.elem + i);
    }

    cout << "kopiuj: " << name << "\n";

}

/*
 * Destructor
 */
Table::~Table() {
    delete[] elem;

    cout << "usuwam: " << name << "\n";
}

/*
 * Operators
 */
Table &Table::operator=(const Table &copyOther) {
    int *p = new int[copyOther.size];

    for (int i = 0; i != copyOther.size; ++i) {
        *(p + i) = *(copyOther.elem + i);
    }

    delete[] elem;
    elem = p;
    size = copyOther.size;

    return *this;
}

int &Table::operator[](int index) {
    return elem[index];

}

/*
 * Public Methods
 */
void Table::halfArray() {

    int newSize;

    if (size % 2 != 0) {
        newSize = (size / 2) + 1;
    } else {
        newSize = size / 2;
    }

    int *newTable = new int[newSize];

    for (int i = 0; i != newSize; ++i) {
        if (newSize + i < size) {
            *(newTable + i) = *(elem + (newSize + i)) + *(elem + i);
        } else {
            *(newTable + i) = *(elem + i);
        }
    }

    delete[] elem;
    elem = newTable;
    size = newSize;

}

void Table::setName(string newName) {
    Table::name = newName;
}

string Table::getName() {
    return name;
}

bool Table::setSize(int newSize) {
    if (0 < newSize) {
        int *p = new int[newSize];

        int overflowAwareSize = (newSize < size) ? newSize : size;

        for (int i = 0; i != overflowAwareSize; ++i) {
            *(p + i) = *(this->elem + i);
        }

        delete[] elem;
        elem = p;

        Tools::initializeWithZeros(elem, size, newSize);
        size = newSize;

        return true;
    } else
        return false;
}

int Table::getSize() {
    return size;
}

bool Table::setVaule(int index, int value) {

    if (Tools::indexCheck(index, 0, size)) {
        elem[index] = value;
        return true;
    } else
        return false;
}

/*
 * -1 is the code of unsuccessful operation
 */
int Table::getValue(int index, bool *opSuccess) {
    if (Tools::indexCheck(index, 0, size)) {
        *opSuccess = true;
        return elem[index];
    } else {
        *opSuccess = false;
        return -1;
    }
}

Table *Table::clone() {
    return new Table(*this);
}

string Table::toString() {
    stringstream objectOutput;
    objectOutput << "[ ";
    objectOutput << name;
    objectOutput << " len: " << size;
    objectOutput << " values: ";

    for (int i = 0; i < size; ++i) {
        objectOutput << elem[i];

        if (i != size - 1) {
            objectOutput << ", ";
        }
    }
    objectOutput << " ]";

    return objectOutput.str();
}