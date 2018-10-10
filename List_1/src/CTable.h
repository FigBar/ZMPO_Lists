//
// Created by fig_bar98 on 06.10.18.
//

#include <string>

#ifndef LIST_1_CTABLE_H
#define LIST_1_CTABLE_H


using namespace std;

class CTable {

public:
    //Constructors
    CTable();

    CTable(string newName, int tableLength);

    CTable(const CTable &copyOther);                //copy constructor
    //__________________________________________________________________

    //Destructor
    ~CTable();
    //__________________________________________________________________

    //Operators
    CTable &operator=(const CTable &copyOther);     //copy assignment

    int &operator[](int index);

    //Methods
    void setName(string newName);

    string getName();

    int getSize();

    bool setSize(int newSize);

    bool setVaule(int index, int value);

    int getValue(int index, bool *opSuccess);

    CTable *clone();

    string toString();


    //___________________________________________________________________

private:

    //Constants
    const int DEFAULT_SIZE;
    const string DEFAULT_NAME;

    //Class fields
    int *elem;
    int size;
    string name;


};

#endif //LIST_1_CTABLE_H
