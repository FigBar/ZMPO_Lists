//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_TABLE_H
#define LIST_2_TABLE_H
#include<string>
using namespace std;

class Table {
public:
    //Constructors
    Table();

    Table(string newName, int tableLength);

    Table(const Table &copyOther);                //copy constructor
    //__________________________________________________________________

    //Destructor
    ~Table();
    //__________________________________________________________________

    //Operators
    Table &operator=(const Table &copyOther);     //copy assignment

    int &operator[](int index);

    //Methods
    void halfArray();

    void setName(string newName);

    string getName();

    int getSize();

    bool setSize(int newSize);

    bool setVaule(int index, int value);

    int getValue(int index, bool *opSuccess);

    Table *clone();

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


#endif //LIST_2_TABLE_H
