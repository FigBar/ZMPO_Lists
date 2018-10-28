//
// Created by fig_bar98 on 28.10.18.
//

#ifndef LIST_3_MENUANALYZER_H
#define LIST_3_MENUANALYZER_H


#include "../user_interface/Menu.h"

class MenuAnalyzer {
public:
    void searchForCommand(const string &commandToFind, string &path);
    void setMainMenu (Menu &mainMenu);

private:
    Menu *mainMenu;
};


#endif //LIST_3_MENUANALYZER_H
