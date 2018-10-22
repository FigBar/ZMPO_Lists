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


void Menu::initializeMenu(TableHandler &handler1) {

    Menu *creationMenu;
    creationMenu = new Menu("Create Tables", "create");
    creationMenu->addMenuItem(new MenuCommand("Create one Table", "one", new createSingleTable(handler1)));
    creationMenu->addMenuItem(new MenuCommand("Create multiple Tables", "multiple", new createMultipleTables(handler1)));
    creationMenu->addMenuItem(new MenuCommand("Clone a Table and append it", "clone", new CloneTable(handler1)));

    this->addMenuItem(creationMenu);

    Menu *changeMenu;
    changeMenu = new Menu("change Tables", "change");
    changeMenu->addMenuItem(new MenuCommand("Set Name", "sName", new SetName(handler1)));
    changeMenu->addMenuItem(new MenuCommand("Set Size", "sSize", new SetSize(handler1)));
    changeMenu->addMenuItem(new MenuCommand("Insert Number", "insert", new InsertNumber(handler1)));
    //changeMenu->addMenuItem(new MenuCommand("Default", "Default", new Command));

    this->addMenuItem(changeMenu);

    Menu *removeMenu;
    removeMenu = new Menu("remove Tables", "remove");
    removeMenu->addMenuItem(new MenuCommand("Delete one", "delete_one", new DeleteOne(handler1)));
    removeMenu->addMenuItem(new MenuCommand("Delete all", "delete_all", new DeleteAll(handler1)));
    this->addMenuItem(removeMenu);

    Menu *printMenu;
    printMenu = new Menu("print Tables", "print");
    printMenu->addMenuItem(new MenuCommand("Print one", "print_one", new PrintTable(handler1)));
    printMenu->addMenuItem(new MenuCommand("Print all", "print_all", new PrintAll(handler1)));
    this->addMenuItem(printMenu);
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


