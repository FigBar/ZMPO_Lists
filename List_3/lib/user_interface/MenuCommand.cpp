//
// Created by Bartosz Figiel on 19.10.2018.
//

#include <iostream>
#include "MenuCommand.h"
#include "Command.h"


MenuCommand::MenuCommand(string nameGiven, string commandGiven) {
    name = nameGiven;
    command = commandGiven;
    this->helpPrompt = "Default help prompt";
}

MenuCommand::MenuCommand(string nameGiven, string commandGiven, string helpPrompt) {
    name = nameGiven;
    command = commandGiven;
    this->helpPrompt = helpPrompt;
}

MenuCommand::MenuCommand(string nameGiven, string commandGiven, Command *comObject) {
    name = nameGiven;
    command = commandGiven;
    command1 = comObject;
    this->helpPrompt = "Default help prompt";
}

MenuCommand::MenuCommand(string nameGiven, string commandGiven, Command *comObject, string helpPrompt) {
    name = nameGiven;
    command = commandGiven;
    command1 = comObject;
    this->helpPrompt = helpPrompt;
}

MenuCommand::~MenuCommand() {
    cout << DELETION_PROMPT << this->getName() << endl;
    if (command1)
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

string MenuCommand::getHelp() {
    return this->helpPrompt;
}

string MenuCommand::getName() {
    return this->name;
}



