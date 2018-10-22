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

using namespace std;
#define MAIN_MENU_NAME "Main Menu"
#define DEFAULT_NAME "Menu"
#define DEFAULT_COMMAND "No commands"
#define FINISH "back"

Menu::Menu() {
    name = DEFAULT_NAME;
    command = DEFAULT_COMMAND;
}

Menu::Menu(string nameGiven, string commandGiven) {
    name = nameGiven;
    command = commandGiven;
}

Menu::~Menu() {
    for (int i = 0; i < menuItems.size(); ++i) {
        cout << "deleting Menu: " + menuItems[i]->getName() << endl;
        delete menuItems[i];
    }
    menuItems.clear();
}

void Menu::run() {
    this->toString();
    MenuItem *item;
    while ((item = this->findMenuItem())!= nullptr){
        item->run();
        this->toString();
    }
    if(name == MAIN_MENU_NAME){
        cout << "Finishing program." << endl;
        delete this;
    }
}

void Menu::toString() {
    cout << "Menu name: " << name << endl << "Menu command: " << command << endl;
    cout << "_________________________________________________" << endl;
    for (int i = 0; i < menuItems.size(); ++i) {
        stringstream stream1;
        stream1 << i + 1 << ". ";
        stream1 << "Name: ";
        stream1 << menuItems[i]->getName() << endl;
        stream1 << "Command: ";
        stream1 << menuItems[i]->getCommand() << endl;
        string str1 = stream1.str();
        cout << str1;
    }
    cout <<"___________________________________________________" << endl;
}





MenuItem *Menu::findMenuItem() {
    string givenCommand;
    while ((givenCommand = Utils::provideString()) != FINISH) {
        for (int i = 0; i < menuItems.size(); ++i) {
            if(menuItems[i]->getCommand() == givenCommand)
                return menuItems[i];
        }
        cout << "Invalid command, try again :/" << endl;
    }
    return nullptr;
}

void Menu::addMenuItem(MenuItem *itemToAdd) {
    bool contains = false;
    for (int i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i]->getName() == itemToAdd->getName() || menuItems[i]->getCommand() == itemToAdd->getCommand())
            contains = true;
    }
    if (!contains)
        menuItems.push_back(itemToAdd);
}

string Menu::getName() {
    return this->name;
}

string Menu::getCommand() {
    return this->command;
}


