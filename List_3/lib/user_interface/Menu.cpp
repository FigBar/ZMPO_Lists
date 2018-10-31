//
// Created by Bartosz Figiel on 19.10.2018.
//

#include "Menu.h"
#include "../utils/Utils.h"
#include "../utils/MenuAnalyzer.h"
#include "MenuCommand.h"
#include "../utils/MenuSerializer.h"
#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;


Menu::Menu() {
    name = MENU_1;
    command = COMMAND_1;
}

Menu::Menu(string nameGiven, string commandGiven, MenuAnalyzer &analyzer) {
    name = nameGiven;
    command = commandGiven;
    this->analyzer = &analyzer;
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
    bool valid = false;
    do {
        this->toString();
        cout << USERS_CHOICE_REQUEST << endl;

        userChoice = Utils::provideString();
        transform(userChoice.begin(), userChoice.end(), userChoice.begin(), ::tolower);
        if (userChoice.length() > MIN_HELP_LENGTH && userChoice.substr(0, MIN_HELP_LENGTH) == HELP_COMMAND) {
            valid = showDescription(userChoice.substr(MIN_HELP_LENGTH, userChoice.length()));
        } else if (userChoice.length() > MIN_SEARCH_LENGTH &&
                   userChoice.substr(0, MIN_SEARCH_LENGTH) == SEARCH_COMMAND) {

            analyzer->searchForCommand(NULL, userChoice.substr(MIN_SEARCH_LENGTH, userChoice.length()), "", valid);
        } else if (userChoice.length() > MIN_SAVE_LENGTH && userChoice.substr(0, MIN_SAVE_LENGTH) == SAVE_COMMAND) {
            string fileName = userChoice.substr(MIN_SAVE_LENGTH, userChoice.length());
            valid = MenuSerializer::serializeToFile(this, fileName);
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
        stream1 << menuItems[i]->getName() << " ";
        stream1 << "(" << menuItems[i]->getCommand() << ")" << endl;
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
            if (MenuCommand *menuCommand = dynamic_cast<MenuCommand *>(menuItems[i])) {
                cout << endl << menuCommand->getHelp() << endl;
                return true;
            }
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

vector<MenuItem *> Menu::getVector() {
    return menuItems;
}


