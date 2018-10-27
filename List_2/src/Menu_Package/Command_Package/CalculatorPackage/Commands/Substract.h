//
// Created by fig_bar98 on 25.10.18.
//

#ifndef LIST_2_SUBSTRACT_H
#define LIST_2_SUBSTRACT_H


#define SUBSTRACT_PROMPT "The outcome of substraction of a & b is: "

#include "../CalculatorCommand.h"


class Substract : public CalculatorCommand{

public:
    Substract(int &a, int &b);
    void runCommand();
};


#endif //LIST_2_SUBSTRACT_H
