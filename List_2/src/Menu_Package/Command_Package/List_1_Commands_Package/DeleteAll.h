//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_DELETEALL_H
#define LIST_2_DELETEALL_H


#include "../Command.h"

class DeleteAll : public Command{
public:
    void runCommand();
    void deleteAll();
};


#endif //LIST_2_DELETEALL_H
