//
// Created by fig_bar98 on 25.10.18.
//

#include "Add.h"
#include "CalculatorCommand.h"
#include <iostream>

using namespace std;

void Add::runCommand() {
    cout << "a: " << *a << endl;
    cout << "b: " << *b << endl;
    cout << ADDITION_PROMPT << *a + *b << endl;
}

Add::Add(int &a, int &b) : CalculatorCommand(a, b) {

}
