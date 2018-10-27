//
// Created by fig_bar98 on 25.10.18.
//

#include "Reset.h"
#include <iostream>
using namespace std;

Reset::Reset(int &a, int &b) : CalculatorCommand(a, b) {

}

void Reset::runCommand() {
    *(this->a) = 0;
    *(this->b) = 0;
    cout << "a: " << *a << endl;
    cout << "b: " << *b << endl;
    cout << RESET_PROMPT << endl;
}
