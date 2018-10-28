//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_MENU_H
#define LIST_2_MENU_H


#define DELETION_MENU_PROMPT "Delete Menu: "
#define INVALID_COMMAND "Invalid command, try again :/"
#define FINISH "back"
#define MENU_NAME "Menu name: "
#define MENU_COMMAND "Menu command: "
#define MENU_SEPARATOR "#########################################"
#define NAME "Name: "
#define COMMAND "Command: "

#define COMMAND_1 "Command 1"

#define MIN_HELP_LENGTH 5

#define HELP_COMMAND "help "

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

    bool findMenuItemAndRun(const string &commandToRun);

    bool showDescription(const string &commandToFind);

    bool addMenuItem(MenuItem *itemToAdd);

    bool deleteMenuItem(string command);


private:
    vector<MenuItem *> menuItems;

};


#endif //LIST_2_MENU_H
