//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_MENUITEM_H
#define LIST_2_MENUITEM_H

#include <string>

using  namespace std;

class MenuItem {

public:

    virtual void Run() = 0;

private:
    string command;
    string name;
};


#endif //LIST_2_MENUITEM_H
