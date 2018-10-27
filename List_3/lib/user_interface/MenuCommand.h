//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_MENUCOMMAND_H
#define LIST_2_MENUCOMMAND_H

#define DELETION_PROMPT "###Deleting MenuCommand: "
#define EMPTY_COMMAND "Empty command"

#include "MenuItem.h"
#include "Command.h"


class MenuCommand : public MenuItem {

public:
    MenuCommand(string nameGiven, string commandGiven);

    MenuCommand(string nameGiven, string commandGiven, Command *comObject);

    ~MenuCommand();

    void run();

    string getCommand();

    string getName();

private:
    Command *command1;
};


#endif //LIST_2_MENUCOMMAND_H
