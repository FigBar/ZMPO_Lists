//
// Created by fig_bar98 on 25.10.18.
//

#include "Substract.h"
#include <iostream>

using namespace std;

Substract::Substract(int &a, int &b) : CalculatorCommand(a, b) {

}

void Substract::runCommand() {
    cout << "a: " << *a << endl;
    cout << "b: " << *b << endl;
    cout << SUBSTRACT_PROMPT << *a - *b << endl;
}
