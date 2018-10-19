//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_MENU_H
#define LIST_2_MENU_H


#include <vector>
#include "MenuItem.h"
using namespace std;

class Menu : protected MenuItem {

protected:
    void Run();

private:
    vector<MenuItem*> menuItems;
};


#endif //LIST_2_MENU_H
