//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_MENUCOMMAND_H
#define LIST_2_MENUCOMMAND_H

#include "MenuItem.h"
#include "Command_Package/Command.h"


class MenuCommand : protected MenuItem {

public:
    MenuCommand(string nameGiven, string commandGiven);

    MenuCommand(string nameGiven, string commandGiven, Command *comObject);

    ~MenuCommand();

    void run();

    string getCommand();


private:
    Command *command1;
};


#endif //LIST_2_MENUCOMMAND_H
