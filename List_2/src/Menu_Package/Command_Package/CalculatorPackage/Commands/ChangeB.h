//
// Created by fig_bar98 on 25.10.18.
//

#ifndef LIST_2_CHANGEB_H
#define LIST_2_CHANGEB_H


#define B_VALUE_REQUEST "Please provide an integer you want to assign to b: "

#include "../CalculatorCommand.h"

class ChangeB : public CalculatorCommand {
public:
    ChangeB(int &a, int &b);

    void runCommand();
};


#endif //LIST_2_CHANGEB_H
