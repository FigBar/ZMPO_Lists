//
// Created by Bartosz Figiel on 19.10.2018.
//

#include <iostream>
#include "MenuCommand.h"


MenuCommand::MenuCommand(string nameGiven, string commandGiven) {
    name = nameGiven;
    command = commandGiven;
}

MenuCommand::MenuCommand(string nameGiven, string commandGiven, Command *comObject) {
    name = nameGiven;
    command = commandGiven;
    command1 = comObject;
}

MenuCommand::~MenuCommand() {
    cout << DELETION_PROMPT << this->getName() << endl;
    delete command1;
}

void MenuCommand::run() {
    if (command1)
        command1->runCommand();
    else {
        cout << EMPTY_COMMAND;
        cout << endl;
    }
}

string MenuCommand::getCommand() {
    return this->command;
}

string MenuCommand::getName() {
    return this->name;
}



