//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_MENU_H
#define LIST_2_MENU_H


#include <vector>
#include "MenuItem.h"
#include "TableHandler_Package/TableHandler.h"

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

    MenuItem *findMenuItem();

    bool addMenuItem(MenuItem *itemToAdd);
    bool deleteMenuItem(string command);


private:
    vector<MenuItem *> menuItems;
};


#endif //LIST_2_MENU_H
