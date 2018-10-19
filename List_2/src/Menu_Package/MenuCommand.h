//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_MENUCOMMAND_H
#define LIST_2_MENUCOMMAND_H
#include "MenuItem.h"
#include "Command.h"


class MenuCommand : protected MenuItem {

protected:
    void Run();

private:
    Command* command1;
};


#endif //LIST_2_MENUCOMMAND_H
