//
// Created by fig_bar98 on 25.10.18.
//

#ifndef LIST_2_RESET_H
#define LIST_2_RESET_H


#define RESET_PROMPT "A & B have been reset"

#include "../CalculatorCommand.h"

class Reset : public CalculatorCommand{
public:
    Reset(int &a, int &b);

    void runCommand();
};


#endif //LIST_2_RESET_H
