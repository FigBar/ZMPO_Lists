//
// Created by fig_bar98 on 25.10.18.
//
#include <iostream>
#include <climits>
#include "ChangeA.h"
#include "../../../lib/utils/Utils.h"

using namespace std;
ChangeA::ChangeA(int &a, int &b) : CalculatorCommand(a, b) {

}

void ChangeA::runCommand() {
    cout << A_VALUE_REQUEST << endl;
    int newValue = Utils::provideInt(-INT_MAX, INT_MAX);
    *(this->a) = newValue;
    cout << "a: " << *a << endl;
}
