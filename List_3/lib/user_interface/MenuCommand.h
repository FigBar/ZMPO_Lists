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

    MenuCommand(string nameGiven, string commandGiven, string helpPrompt);

    MenuCommand(string nameGiven, string commandGiven, Command *comObject);

    MenuCommand(string nameGiven, string commandGiven, Command *comObject, string helpPrompt);

    ~MenuCommand();

    void run();

    string getCommand();

    string getName();

    string getHelp();

private:
    Command *command1;
    string helpPrompt;
};


#endif //LIST_2_MENUCOMMAND_H
