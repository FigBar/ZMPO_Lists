//
// Created by fig_bar98 on 28.10.18.
//

#ifndef LIST_3_MENUANALYZER_H
#define LIST_3_MENUANALYZER_H

#include <string>
using namespace std;

class Menu;
class MenuAnalyzer {
public:
    void searchForCommand(Menu *menu, const string &commandToFind, string path, bool &found);
    void setMainMenu (Menu &mainMenu);

private:
    Menu *mainMenu = NULL;
};


#endif //LIST_3_MENUANALYZER_H
