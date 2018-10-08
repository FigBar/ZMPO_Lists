//
// Created by fig_bar98 on 07.10.18.
//

#include "CRun.h"
#include "CTable.h"
#include <vector>
#include <iostream>
#include <limits>

CRun::CRun() {

    //*success = true;

}

CRun::~CRun() {

    for (int i = 0; i < tableVector.size(); ++i) {
        delete tableVector[i];
    }
    tableVector.clear();

    //delete success;
}

void CRun::start() {
    bool toContinue = true;

    while (toContinue) {

        std::cout << "------MENU------" << "\n"
                  << "0. Create a single CTable object" << "\n"
                  << "1. Create an unrestricted number of CTable objects" << "\n"
                  << "2. Delete all CTable objects" << "\n"
                  << "3. Delete a specified CTable object" << "\n"
                  << "4. Set size of a specified CTable object" << "\n"
                  << "5. Set name to a specified CTable object" << "\n"
                  << "6. Clone a specified CTable object and append it to the list" << "\n"
                  << "7. Get information about specified CTable object" << "\n"
                  << "8. Insert a number to a specified CTable" << "\n"
                  << "9. Print all CTable objects" << "\n"
                  << "10. End program" << "\n\n";


        std::cout << "Please provide the number of operation you want to be carried out." << "\n";
        int opNumber = provideInt();

        switch (opNumber) {
            case 0:
                if (yesOrNo()) {
                    cout << "Now let's give your CTable a name." << "\n";
                    string givenName = provideString();

                    cout << "Ok, what should be its length?" << "\n";
                    int givenInt = provideInt();
                    addParametrizedSingleCTable(givenName, givenInt);

                } else {
                    addSingleCTable();
                }
                break;

            case 1:
                int amount;
                cout << "How many CTable object do you want to create?" << "\n";
                cin >> amount;

                if (yesOrNo()) {
                    for (int i = 0; i < amount; ++i) {
                        cout << "Now let's give your CTable a name." << "\n";
                        string givenName = provideString();

                        cout << "Ok, what should be its length?" << "\n";
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

            case 9:

                for(CTable* table : tableVector){
                    cout << table->toString() << endl;
                }
                break;

            case 10:
                toContinue = false;
                break;

            default:
                cout << "Try again :/" << "\n\n";
                break;


        }
    }
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
    cout << "Please provide a string." << "\n";
    cin >> givenName;

    return givenName;
}

int CRun::provideInt() {

    int givenInt;

    cout << "Please provide an integer value." << "\n";

    while (!(cin >> givenInt)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again, you provided wrong data." << endl;
    }
    return givenInt;
}

bool CRun::yesOrNo() {

    string choice;
    cout << "Do you want to create a parametrized object? (Yes/No)" << "\n";
    cin >> choice;

    return (choice.at(0) == 'Y' || choice.at(0) == 'y');

}