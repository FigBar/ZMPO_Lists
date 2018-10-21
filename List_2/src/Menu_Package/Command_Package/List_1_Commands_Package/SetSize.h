//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_SETSIZE_H
#define LIST_2_SETSIZE_H


#include "../Command.h"

class SetSize : public Command {
public:
    void runCommand();
    bool changeSize(int index, int newSize);
};


#endif //LIST_2_SETSIZE_H
