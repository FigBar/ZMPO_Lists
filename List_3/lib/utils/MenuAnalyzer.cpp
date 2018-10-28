//
// Created by fig_bar98 on 28.10.18.
//

#include "MenuAnalyzer.h"
#include "../user_interface/MenuCommand.h"
#include "../user_interface/Menu.h"
#include <iostream>

void MenuAnalyzer::searchForCommand(Menu *menu, const string &commandToFind, string path) {
    if (!menu) {
        menu = mainMenu;
    }
    if (menu != mainMenu)
        path += "->";
    path += menu->getCommand();
    vector<MenuItem *> menuItems = menu->getVector();
    for (int i = 0; i < menuItems.size(); ++i) {
        if (menuItems[i]->getCommand() == commandToFind) {
            cout << path << "->" << menuItems[i]->getCommand() << endl;
        }
        if (Menu *next = dynamic_cast<Menu *>(menuItems[i])) {
            searchForCommand(next, commandToFind, path);
        }
    }
}

void MenuAnalyzer::setMainMenu(Menu &mainMenu) {
    this->mainMenu = &mainMenu;
}
