//
// Created by Bartosz Figiel on 19.10.2018.
//

#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(string nameGiven, string commandGiven) {
    name = nameGiven;
    command = commandGiven;
}

Menu::~Menu() {
    for (int i = 0; i < menuItems.size() ; ++i) {
        delete menuItems[i];
    }
    menuItems.clear();
}

void Menu::run() {

}

void Menu::toString() {

}

string Menu::getCommand() {
    return command;
}

void Menu::initializeMenu() {

}

bool Menu::ifCommandExists() {
    cin >> providedCommand;
    if(providedCommand == "back")
        return true;
    for (int i = 0; i < menuItems.size(); ++i) {
        if(menuItems[i]->getCommand() == providedCommand)
            return true;
    }
    return false;
}

void Menu::findCommandAndRun() {
    if(providedCommand != "back"){
        for (int i = 0; i <menuItems.size() ; ++i) {
            if(menuItems[i]->getCommand() == providedCommand)
                menuItems[i]->run();
        }
    }
}

void Menu::addMenu() {

}

void Menu::addMenuCommand() {

}


