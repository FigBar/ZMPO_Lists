#include <iostream>
#include "Menu.h"
int main() {
    Menu *mainMenu = new Menu("Main Menu", "main");
    TableHandler *handler1 = new TableHandler();
    mainMenu->initializeMenu(*handler1);
    mainMenu->run();
    delete handler1;
    return 0;
}