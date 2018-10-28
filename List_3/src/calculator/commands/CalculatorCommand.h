//
// Created by fig_bar98 on 25.10.18.
//

#ifndef LIST_2_CALCULATORCOMMAND_H
#define LIST_2_CALCULATORCOMMAND_H



#include "../../../lib/user_interface/Command.h"

class CalculatorCommand : public Command {
public:
    CalculatorCommand(int &a, int &b);

protected:
    int *a;
    int *b;
};


#endif //LIST_2_CALCULATORCOMMAND_H
