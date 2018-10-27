//
// Created by fig_bar98 on 25.10.18.
//

#include "CalculatorCommand.h"

CalculatorCommand::CalculatorCommand(int &a, int &b) {
    this->a = &a;
    this->b = &b;
}
