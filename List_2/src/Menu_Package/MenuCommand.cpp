//
// Created by Bartosz Figiel on 19.10.2018.
//

#include <iostream>
#include "MenuCommand.h"
#define DEFAULT_COMMAND "Empty command";

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
    cout << "Deleting MenuCommand: " << this->getName() << endl;
    delete command1;
}

void MenuCommand::run() {
    if(command1)
        command1 ->runCommand();
    else {
        cout << DEFAULT_COMMAND;
        cout << endl;
    }
}

string MenuCommand::getCommand() {
    return this->command;
}

string MenuCommand::getName() {
    return this->name;
}



