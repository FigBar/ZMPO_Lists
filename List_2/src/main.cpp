#include <iostream>
#include "Menu_Package/Menu.h"
#include "Menu_Package/Initializer.h"

int main() {
    Menu *mainMenu;
    TableHandler *handler1 = new TableHandler();
    mainMenu = Initializer::initialize(*handler1);
    mainMenu->run();
    delete handler1;
    return 0;
}