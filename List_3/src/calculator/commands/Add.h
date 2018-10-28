//
// Created by fig_bar98 on 25.10.18.
//

#ifndef LIST_2_ADD_H
#define LIST_2_ADD_H


#define ADDITION_PROMPT "The outcome of addition of a & b is: "


#include "CalculatorCommand.h"

class Add : public CalculatorCommand {
public:
    Add(int &a, int &b);

    void runCommand();
};


#endif //LIST_2_ADD_H
