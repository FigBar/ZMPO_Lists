//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_MENU_H
#define LIST_2_MENU_H


#include <vector>
#include "MenuItem.h"
using namespace std;

class Menu : protected MenuItem {

public:
    Menu(string name, string command);

    ~Menu();

    void run();

    void toString();

    string getCommand();

    string getName();

    void initializeMenu();

    bool ifCommandExists();

    void findCommandAndRun();

    void addMenu();

    void addMenuCommand();





private:
    vector<MenuItem*> menuItems;
    string providedCommand;
};


#endif //LIST_2_MENU_H
