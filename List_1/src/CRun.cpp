//
// Created by fig_bar98 on 07.10.18.
//

#include "CRun.h"
#include "CTable.h"
#include "Tools.h"
#include <vector>
#include <iostream>
#include <limits>
#include <climits>

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

        menu();
        std::cout << "Please provide the number of operation you want to be carried out." << endl;
        int opNumber = Tools::provideAnInt(0, 10);

        switch (opNumber) {
            case 0:
                if (Tools::yesOrNo()) {
                    cout << "Now let's give your CTable a name." << endl;
                    string givenName = Tools::provideString();

                    cout << "Ok, what should be its length?" << endl;
                    int givenInt = Tools::provideInt(0, INT_MAX);
                    addParametrizedSingleCTable(givenName, givenInt);

                } else {
                    addSingleCTable();
                }
                break;

            case 1:
                int amount;
                cout << "How many CTable object do you want to create?" << endl;
                amount = Tools::provideInt(0, INT_MAX);
                if (Tools::yesOrNo()) {
                    for (int i = 0; i < amount; ++i) {
                        cout << "Now let's give your CTable a name." << "\n";
                        string givenName = Tools::provideString();
                        cout << "Ok, what should be its length?" << endl;
                        int givenInt = Tools::provideInt(0, INT_MAX);
                        addParametrizedSingleCTable(givenName, givenInt);
                    }
                } else {
                    for (int i = 0; i < amount; ++i) {
                        addSingleCTable();
                    }
                }
                break;

            case 2:
                deleteAll();
                break;

            case 3:
                int index;
                if(!tableVector.empty()) {
                    cout << "Please provide the number of CTable object you want to remove." << endl;
                    index = Tools::provideAnInt(0, tableVector.size() - 1);
                    if (removeCTable(index)) {
                        cout << "Operation carried out successfully" << endl;
                    } else {
                        cout << "Operation failed, you provided invalid index :/" << endl;
                    };
                } else {
                    cout << "There's nothing to remove." << endl;
                }
                break;

            case 4:
                if(!tableVector.empty()) {
                    cout << "Please provide index of CTable you want to modify" << endl;
                    index = Tools::provideAnInt(0, tableVector.size() - 1);
                    cout << "Now provide new length of chosen CTable" << endl;
                    int newSize;
                    newSize = Tools::provideInt(1, INT_MAX);

                    if (changeSize(index, newSize)) {
                        cout << "Operation carried out successfully" << endl;
                    } else {
                        cout << "Operation failed, you provided invalid index or invalid table length :/" << endl;
                    };
                } else {
                    cout << "The list of CTables is empty" << endl;
                }
                break;

            case 5:
                if(!tableVector.empty()) {
                    cout << "Please provide index of CTable you want to modify" << endl;
                    index = Tools::provideAnInt(0, tableVector.size() - 1);
                    cout << "Please provide new name of chosen CTable" << endl;
                    if (changeName(index, Tools::provideString())) {
                        cout << "Operation carried out successfully" << endl;
                    } else {
                        cout << "Operation failed, you provided invalid index :/" << endl;
                    };
                } else {
                    cout << "The list of CTables is empty" << endl;
                }
                break;

            case 6:
                if(!tableVector.empty()) {
                    cout << "Please provide index of CTable you want to clone" << endl;
                    index = Tools::provideAnInt(0, tableVector.size() - 1);
                    if (appendClone(index)) {
                        cout << "Operation carried out successfully" << endl;
                    } else {
                        cout << "Operation failed, you provided invalid index :/" << endl;
                    };
                } else {
                    cout << "The list of CTables is empty" << endl;
                }
                break;

            case 7:
                if(!tableVector.empty()) {
                    cout << "Please provide index of CTable you want to get information about" << endl;
                    index = Tools::provideAnInt(0, tableVector.size() - 1);
                    if (index >= 0 && index < tableVector.size()) {
                        cout << tableVector[index]->toString() << endl;

                    } else
                        cout << "Operation failed, you provided invalid index :/" << endl;
                } else {
                    cout << "The list of CTables is empty" << endl;
                }
                break;

            case 8:
                if(!tableVector.empty()) {
                    int vectorIndex;
                    int value;
                    cout << "Please provide index of CTable to which you want to assign a new value" << endl;
                    vectorIndex = Tools::provideAnInt(0, tableVector.size() - 1);
                    cout << "Now provide CTable's index you want to assign to" << endl;
                    index = Tools::provideAnInt(0, tableVector.at(vectorIndex)->getSize() - 1);
                    cout << "At final, please provide the value you want to assign" << endl;
                    value = Tools::provideInt(-INT_MAX, INT_MAX);

                    if (setValueInCTable(vectorIndex, index, value)) {
                        cout << "Operation carried out successfully" << endl;
                    } else {
                        cout << "Operation failed, you provided invalid index :/" << endl;
                    };
                } else {
                    cout << "The list of CTables is empty" << endl;
                }
                break;

            case 9:
                if(!tableVector.empty()) {
                    cout << "------LIST_OF_CTABLE_OBJECTS------" << endl;
                    for (int i = 0; i < tableVector.size(); ++i) {
                        cout << i << ". " << tableVector[i]->toString() << endl;
                    }
                    break;
                } else {
                    cout << "The list of CTables is empty" << endl;
                }

            case 10:
                toContinue = false;
                break;

            default:
                cout << "Try again :/" << endl << endl;
                break;


        }
    }
}

void CRun::menu() {
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
    } else return false;


}

void CRun::deleteAll() {
    if (tableVector.size() == 0)
        cout << "There's nothing to delete" << endl;

    for (int i = 0; i < tableVector.size(); ++i) {
        delete tableVector[i];
    }
    tableVector.clear();
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



