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
    //__________________________________________________________________

    //destructor
    ~CTable();
    //__________________________________________________________________

    //Methods
    CTable& operator=(const CTable& copyOther);     //copy assignment
    void setName(string newName);
    int& operator[](int index);
    int getSize() const;
    void setSize(int newSize);
    bool setVaule(int value, int index);
    int getValue(int index, bool* opSuccess);
    CTable clone();
    string toString();


    //___________________________________________________________________

private:
    //methods
    bool indexCheck(int index);
    bool initializeWithZeros(int start, int end);
    //constants
    const int DEFAULT_SIZE;
    const string DEFAULT_NAME;

    //class fields
    int* elem;
    int size;
    string name;



};
