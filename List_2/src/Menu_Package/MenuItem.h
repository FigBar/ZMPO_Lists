//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_MENUITEM_H
#define LIST_2_MENUITEM_H

#include <string>

using  namespace std;

class MenuItem {

public:

    virtual void run() = 0;
    virtual void toString()=0;
    virtual string getCommand()=0;

protected:
    string command;
    string name;
};


#endif //LIST_2_MENUITEM_H
