//
// Created by fig_bar98 on 07.10.18.
//

#include "CRun.h"
#include "CTable.h"
#include <vector>
#include <iostream>

CRun::CRun() {

    *success = true;

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
                  << "9. End program" << "\n";

        bool opNumber;
        std::cout << "Please provide the number of operation you want to be carried out." << "\n";
        std::cin >> opNumber;

        switch (opNumber) {
            case 0:
                if (yesOrNo() == 'Y' || yesOrNo() == 'y') {
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
                cout << "How many CTable object do you want to create" << "\n";
                cin >> amount;

                if (yesOrNo() == 'Y' || yesOrNo() == 'y') {
                    cout << "Now let's give your CTable a name." << "\n";
                    string givenName = provideString();

                    cout << "Ok, what should be its length?" << "\n";
                    int givenInt = provideInt();

                    for (int i = 0; i < amount - 1; ++i) {
                        addParametrizedSingleCTable(givenName, givenInt);
                    }
                } else {
                    for (int i = 0; i < amount - 1; ++i) {
                        addSingleCTable();
                    }
                }
                break;
            case 9:
                toContinue = false;
            default:
                cout << "Try again :/" << "\n\n";


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
    cin >> givenInt;

    return givenInt;
}

char CRun::yesOrNo() {

    string choice;
    cout << "Do you want to create a parametrized object? (Yes/No)" << "\n";
    cin >> choice;

    return choice.at(0);
}