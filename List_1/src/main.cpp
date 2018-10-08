#include <iostream>
#include "CRun.h"
using namespace std;
int main() {

    CRun runner;
    bool toContinue = true;

    while(toContinue){

        std::cout << "------MENU------" << "\n"
                    << "1. Create an unrestricted number of CTable objects" << "\n"
                    << "2. Delete all CTable objects" << "\n"
                    << "3. Delete a specified CTable object" << "\n"
                    << "4. Set size of a specified CTable object" << "\n"
                    << "5. Set name to a specified CTable object" << "\n"
                    << "6. Clone a specified CTable object and append it to the list" << "\n"
                    << "7. Get information about specified CTable object" << "\n"
                    << "8. Insert a number to a specified CTable" << "\n";

        bool opNumber;
        std::cout << "Please provide the number of operation you want to be carried out." << "\n";
        std::cin >> opNumber;

        switch (opNumber){
            case 1:
                int objectsAmount;
                cout << "Provide the number of CTable objects you want to create" << "\n";
                cin >> objectsAmount;
                runner.addToVector(objectsAmount);

        }
    }
    return 0;
}