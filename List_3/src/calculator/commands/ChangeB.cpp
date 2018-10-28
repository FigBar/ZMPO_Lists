//
// Created by fig_bar98 on 25.10.18.
//

#include "ChangeB.h"
#include "../../../lib/utils/Utils.h"
#include <iostream>
#include <climits>
using namespace std;
ChangeB::ChangeB(int &a, int &b) : CalculatorCommand(a, b) {

}

void ChangeB::runCommand() {
    cout << B_VALUE_REQUEST << endl;
    int newValue = Utils::provideInt(-INT_MAX, INT_MAX);
    *(this->b) = newValue;
    cout << "b: " << *b << endl;
}
