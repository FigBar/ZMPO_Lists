//
// Created by fig_bar98 on 25.10.18.
//

#ifndef LIST_2_CHANGEA_H
#define LIST_2_CHANGEA_H


#define A_VALUE_REQUEST "Please provide a integer you want to assign to a: "

#include "CalculatorCommand.h"

class ChangeA : public CalculatorCommand {
public:
    ChangeA(int &a, int &b);

    void runCommand();
};


#endif //LIST_2_CHANGEA_H
