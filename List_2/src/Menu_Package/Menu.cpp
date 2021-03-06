//
// Created by Bartosz Figiel on 19.10.2018.
//

#include "Menu.h"
#include "Command_Package/Utils.h"
#include "TableHandler_Package/TableHandler.h"
#include "MenuCommand.h"
#include "Command_Package/List_1_Commands_Package/createSingleTable.h"
#include "Command_Package/List_1_Commands_Package/createMultipleTables.h"
#include "Command_Package/List_1_Commands_Package/CloneTable.h"
#include "Command_Package/List_1_Commands_Package/SetName.h"
#include "Command_Package/List_1_Commands_Package/SetSize.h"
#include "Command_Package/List_1_Commands_Package/InsertNumber.h"
#include "Command_Package/List_1_Commands_Package/DeleteOne.h"
#include "Command_Package/List_1_Commands_Package/DeleteAll.h"
#include "Command_Package/List_1_Commands_Package/PrintTable.h"
#include "Command_Package/List_1_Commands_Package/PrintAll.h"
#include <iostream>
#include <sstream>
#include <algorithm>

#define MENU_1 "Menu 1"
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
    this->toString();
    MenuItem *item;
    while ((item = this->findMenuItem())) {
        item->run();
        this->toString();
    }
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

MenuItem *Menu::findMenuItem() {
    string givenCommand;
    while ((givenCommand = provideCommand()) != FINISH) {
        for (int i = 0; i < menuItems.size(); ++i) {
            if (menuItems[i]->getCommand() == givenCommand)
                return menuItems[i];
        }
        cout << INVALID_COMMAND << endl;
    }
    return nullptr;
}

string Menu::provideCommand() {
    string givenCommand;
    givenCommand = Utils::provideString();
    transform(givenCommand.begin(), givenCommand.end(), givenCommand.begin(), ::tolower);
    return givenCommand;
}

string Menu::getName() {
    return this->name;
}

string Menu::getCommand() {
    return this->command;
}


