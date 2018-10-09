//
// Created by fig_bar98 on 07.10.18.
//

#include "CRun.h"
#include "CTable.h"
#include <vector>
#include <iostream>
#include <limits>

CRun::CRun() {

}

CRun::~CRun() {
    for (int i = 0; i < tableVector.size(); ++i) {
        delete tableVector[i];
    }
    tableVector.clear();
}

void CRun::start() {
    bool toContinue = true;

    while (toContinue) {

        std::cout << "------MENU------" << endl
                  << "0. Create a single CTable object" << endl
                  << "1. Create an unrestricted number of CTable objects" << endl
                  << "2. Delete all CTable objects" << endl
                  << "3. Delete a specified CTable object" << endl
                  << "4. Set size of a specified CTable object" << endl
                  << "5. Set name to a specified CTable object" << endl
                  << "6. Clone a specified CTable object and append it to the list" << endl
                  << "7. Get information about specified CTable object" << endl
                  << "8. Insert a number to a specified CTable" << endl
                  << "9. Print all CTable objects" << endl
                  << "10. End program" << endl << endl;


        std::cout << "Please provide the number of operation you want to be carried out." << endl;
        int opNumber = provideInt();

        switch (opNumber) {
            case 0:
                if (yesOrNo()) {
                    cout << "Now let's give your CTable a name." << endl;
                    string givenName = provideString();

                    cout << "Ok, what should be its length?" << endl;
                    int givenInt = provideInt();
                    addParametrizedSingleCTable(givenName, givenInt);

                } else {
                    addSingleCTable();
                }
                break;

            case 1:
                int amount;
                cout << "How many CTable object do you want to create?" << endl;
                amount = provideInt();
                if (yesOrNo()) {
                    for (int i = 0; i < amount; ++i) {
                        cout << "Now let's give your CTable a name." << "\n";
                        string givenName = provideString();
                        cout << "Ok, what should be its length?" << endl;
                        int givenInt = provideInt();
                        addParametrizedSingleCTable(givenName, givenInt);
                    }
                } else {
                    for (int i = 0; i < amount; ++i) {
                        addSingleCTable();
                    }
                }
                break;

            case 2:
                for (int i = 0; i < tableVector.size(); ++i) {
                    delete tableVector[i];
                }
                tableVector.clear();
                break;

            case 3:
                cout << "Please provide the number of CTable object you want to remove." << endl;
                int index;
                index = provideInt();
                if (removeCTable(index)) {
                    cout << "Operation carried out successfully" << endl;
                } else {
                    cout << "Operation failed, you provided invalid index :/" << endl;
                };
                break;

            case 4:
                cout << "Please provide index of CTable you want to modify" << endl;
                index = provideInt();
                cout << "Now provide new length of chosen CTable" << endl;
                int newSize;
                newSize = provideInt();

                if (changeSize(index, newSize)) {
                    cout << "Operation carried out successfully" << endl;
                } else {
                    cout << "Operation failed, you provided invalid index :/" << endl;
                };
                break;

            case 5:
                cout << "Please provide index of CTable you want to modify" << endl;
                index = provideInt();
                cout << "Please provide new name of chosen CTable" << endl;
                if (changeName(index, provideString())) {
                    cout << "Operation carried out successfully" << endl;
                } else {
                    cout << "Operation failed, you provided invalid index :/" << endl;
                };
                break;

            case 6:
                cout << "Please provide index of CTable you want to clone" << endl;
                index = provideInt();
                if (appendClone(index)) {
                    cout << "Operation carried out successfully" << endl;
                } else {
                    cout << "Operation failed, you provided invalid index :/" << endl;
                };
                break;

            case 7:
                cout << "Please provide index of CTable you want to get information about" << endl;
                index = provideInt();
                if (index >= 0 && index < tableVector.size()) {
                    cout << tableVector[index]->toString() << endl;

                } else
                    cout << "Operation failed, you provided invalid index :/" << endl;
                break;

            case 8:
                int vectorIndex;
                int value;
                cout << "Please provide index of CTable to which you want to assign a new value" << endl;
                vectorIndex = provideInt();
                cout << "Now provide CTable's index you want to assign to" << endl;
                index = provideInt();
                cout << "At final, please provide the value you want to assign" << endl;
                value = provideInt();

                if (setValueInCTable(vectorIndex, index, value)) {
                    cout << "Operation carried out successfully" << endl;
                } else {
                    cout << "Operation failed, you provided invalid index :/" << endl;
                };
                break;

            case 9:
                for (int i = 0; i < tableVector.size(); ++i) {
                    cout << i << ". " << tableVector[i]->toString() << endl;
                }
                break;

            case 10:
                toContinue = false;
                break;

            default:
                cout << "Try again :/" << endl << endl;
                break;


        }
    }
}

bool CRun::setValueInCTable(int vectorIndex, int index, int newValue) {
    if (vectorIndex >= 0 && vectorIndex < tableVector.size()) {
        return tableVector[vectorIndex]->setVaule(index, newValue);
    } else return false;
}

bool CRun::appendClone(int index) {
    if (index >= 0 && index < tableVector.size()) {
        tableVector.push_back(tableVector[index]->clone());
        return true;
    } else return false;
}

bool CRun::changeSize(int index, int newSize) {
    if (index >= 0 && index < tableVector.size()) {
        return tableVector[index]->setSize(newSize);
    } else return false;
}

bool CRun::changeName(int index, string newName) {
    if (index >= 0 && index < tableVector.size()) {
        tableVector[index]->setName(newName);
        return true;
    } else return false;
}

bool CRun::removeCTable(int index) {
    if (index >= 0 && index < tableVector.size()) {
        delete tableVector.at(index);
        tableVector.erase(tableVector.begin() + index);
        return true;
    } else false;


}

void CRun::addParametrizedSingleCTable(string givenName, int givenLength) {
    CTable *pointer;

    pointer = new CTable(givenName, givenLength);
    tableVector.push_back(pointer);
}

void CRun::addSingleCTable() {
    CTable *pointer;

    pointer = new CTable();
    tableVector.push_back(pointer);
}

string CRun::provideString() {

    string givenName;
    cout << "Please provide a string." << endl;
    cin >> givenName;

    return givenName;
}

int CRun::provideInt() {

    int givenInt;

    cout << "Please provide an integer value." << endl;

    while (!(cin >> givenInt)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again, you provided wrong data." << endl;
    }
    return givenInt;
}

bool CRun::yesOrNo() {

    string choice;
    cout << "Do you want to create a parametrized object? (Yes/No)" << endl;
    cin >> choice;

    return (choice.at(0) == 'Y' || choice.at(0) == 'y');

}