//
// Created by Bartosz Figiel on 19.10.2018.
//

#include "Menu.h"
#include "../utils/Utils.h"
#include <iostream>
#include <sstream>
#include <algorithm>

#define MENU_1 "Menu 1"
#define USERS_CHOICE_REQUEST "Please provide the command you want to execute: "
using namespace std;


Menu::Menu() {
    name = MENU_1;
    command = COMMAND_1;
}

Menu::Menu(string nameGiven, string commandGiven) {
    name = nameGiven;
    command = commandGiven;
}

Menu::~Menu() {
    for (int i = 0; i < menuItems.size(); ++i) {
        delete menuItems[i];
    }
    cout << DELETION_MENU_PROMPT + this->getName() << endl;
    menuItems.clear();
}

void Menu::run() {
    string userChoice;
    bool valid;
    do {
        this->toString();
        cout << USERS_CHOICE_REQUEST;

        userChoice = Utils::provideString();
        transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);
        if (userChoice.length() > MIN_HELP_LENGTH && userChoice.substr(0, MIN_HELP_LENGTH) == HELP_COMMAND) {
            valid = showDescription(userChoice.substr(MIN_HELP_LENGTH, userChoice.length()));
        } else {
            valid = findMenuItemAndRun(userChoice);
        }

        if (!valid && userChoice != FINISH)
            cout << INVALID_COMMAND << endl;

    } while (userChoice != FINISH);
}

void Menu::toString() {
    cout << MENU_NAME << name << endl << MENU_COMMAND << command << endl;
    cout << MENU_SEPARATOR << endl;
    for (int i = 0; i < menuItems.size(); ++i) {
        stringstream stream1;
        stream1 << i + 1 << ". ";
        stream1 << NAME;
        stream1 << menuItems[i]->getName() << endl;
        stream1 << COMMAND;
        stream1 << menuItems[i]->getCommand() << endl;
        string str1 = stream1.str();
        cout << str1;
    }
    cout << MENU_SEPARATOR << endl;
}


bool Menu::addMenuItem(MenuItem *itemToAdd) {
    bool contains = false;
    for (int i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i]->getName() == itemToAdd->getName() || menuItems[i]->getCommand() == itemToAdd->getCommand())
            contains = true;
    }
    if (!contains)
        menuItems.push_back(itemToAdd);
    return contains;
}

bool Menu::deleteMenuItem(string command) {
    for (int i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i]->getCommand() == command) {
            delete menuItems.at(i);
            menuItems.erase(menuItems.begin() + i);
            return true;
        }
    }
    return false;
}

bool Menu::showDescription(const string &commandToFind) {
    for (int i = 0; i < menuItems.size(); ++i) {
        if (commandToFind == menuItems[i]->getCommand()) {
            cout << endl << menuItems[i]->getName() << endl;
            return true;
        }
    }
    return false;
}

bool Menu::findMenuItemAndRun(const string &commandToRun) {
    for (int i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i]->getCommand() == commandToRun) {
            menuItems[i]->run();
            return true;
        }
    }
    return false;
}


string Menu::getName() {
    return this->name;
}

string Menu::getCommand() {
    return this->command;
}


