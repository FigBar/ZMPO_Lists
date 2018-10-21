//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_MENU_H
#define LIST_2_MENU_H


#include <vector>
#include "MenuItem.h"

using namespace std;

class Menu : public MenuItem {

public:
    Menu();

    Menu(string name, string command);

    ~Menu();

    void run();

    void toString();

    string getCommand();

    string getName();

public:

    void initializeMenu();

    MenuItem *findMenuItem();

    void addMenuItem(MenuItem *itemToAdd);


private:
    vector<MenuItem *> menuItems;
    string providedCommand;
};


#endif //LIST_2_MENU_H
