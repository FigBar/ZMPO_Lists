//
// Created by fig_bar98 on 06.10.18.
//

#include "CTable.h"
#include "iostream"
#include "sstream"
#include "Tools.h"

using namespace std;

/*
 * Constructors
 */
CTable::CTable() : DEFAULT_SIZE(10), DEFAULT_NAME("Table1") {

    elem = new int[DEFAULT_SIZE];
    name = DEFAULT_NAME;
    size = DEFAULT_SIZE;
    Tools::initializeWithZeros(elem, 0, size);

    cout << "bezp: " << name << "\n";
}

CTable::CTable(string newName, int tableLength) : DEFAULT_SIZE(10), DEFAULT_NAME("Table1") {

    elem = new int[tableLength];
    name = newName;
    size = tableLength;
    Tools::initializeWithZeros(elem, 0, size);

    cout << "parametr: " << name << "\n";

}

CTable::CTable(const CTable &copyOther) : DEFAULT_SIZE(10), DEFAULT_NAME("Table1")
{

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
CTable::~CTable()
{
    delete[] elem;

    cout << "usuwam: " << name << "\n";
}

/*
 * Operators
 */
CTable &CTable::operator=(const CTable &copyOther)
{
    int *p = new int[copyOther.size];

    for (int i = 0; i != copyOther.size; ++i) {
        *(p + i) = *(copyOther.elem + i);
    }

    delete[] elem;
    elem = p;
    size = copyOther.size;

    return *this;
}

int &CTable::operator[](int index)
{
    return elem[index];

}

/*
 * Public Methods
 */
void CTable::setName(string newName)
{
    CTable::name = newName;
}

string CTable::getName()
{
    return name;
}

bool CTable::setSize(int newSize)
{
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

int CTable::getSize()
{
    return size;
}

bool CTable::setVaule(int index, int value)
{

    if (Tools::indexCheck(index, 0, size)) {
        elem[index] = value;
        return true;
    } else
        return false;
}

/*
 * -1 is the code of unsuccessful operation
 */
int CTable::getValue(int index, bool *opSuccess)
{
    if (Tools::indexCheck(index, 0, size)) {
        *opSuccess = true;
        return elem[index];
    } else {
        *opSuccess = false;
        return -1;
    }
}

CTable *CTable::clone()
{
    return new CTable(*this);
}

string CTable::toString()
{
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






