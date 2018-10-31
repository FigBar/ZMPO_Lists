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
#define COMMAND_1 "Command 1"
#define MENU_1 "Menu 1"
#define USERS_CHOICE_REQUEST "Please provide the command you want to execute: "
#define MIN_HELP_LENGTH 5
#define HELP_COMMAND "help "
#define MIN_SEARCH_LENGTH 7
#define SEARCH_COMMAND "search "
#define MIN_SAVE_LENGTH 5
#define SAVE_COMMAND "save "

#include <vector>
#include "MenuItem.h"
#include "../utils/MenuAnalyzer.h"


using namespace std;

class Menu : public MenuItem {

public:
    Menu();

    Menu(string name, string command, MenuAnalyzer &analyzer);

    ~Menu();

    void run();

    void toString();

    string getCommand();

    string getName();

    vector<MenuItem *> getVector();

    bool findMenuItemAndRun(const string &commandToRun);

    bool showDescription(const string &commandToFind);

    bool addMenuItem(MenuItem *itemToAdd);

    bool deleteMenuItem(string command);


private:
    vector<MenuItem *> menuItems;
    MenuAnalyzer *analyzer;

};


#endif //LIST_2_MENU_H
