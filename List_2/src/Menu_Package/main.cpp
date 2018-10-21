#include <iostream>
#include "Menu.h"
int main() {
    Menu *mainMenu = new Menu("Main Menu", "main");
    mainMenu->initializeMenu();
    mainMenu->run();
    return 0;
}