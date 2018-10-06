//
// Created by fig_bar98 on 06.10.18.
//

#include <string>

#ifndef LIST_1_CTABLE_H
#define LIST_1_CTABLE_H

#endif //LIST_1_CTABLE_H
using namespace std;

class CTable {

public:
    //constructors
    CTable();
    CTable(string newName, int tableLength);

    CTable(const CTable& copyOther);                //copy constructor
    CTable& operator=(const CTable& copyOther);     //copy assignment

    //__________________________________________________________________

    //destructor
    ~CTable();
    //__________________________________________________________________

    void setName(string newName);
    int& operator[](int index);
    int getSize() const;

private:
    //constants
    const int DEFAULT_SIZE = 10;
    const string DEFAULT_NAME = "Table1";

    //class fields
    int* elem;
    int size;
    string name;



};
