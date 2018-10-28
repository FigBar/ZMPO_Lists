#include <iostream>
#include "../lib/user_interface/Menu.h"
#include "calculator/bootstrap/CalculatorBootstrap.h"
#include "table/domain/TableHandler.h"
#include "table/interface/bootstrap/TableBootstrap.h"

int main() {
    Menu *mainMenu;
    TableHandler *handler1 = new TableHandler();
    mainMenu = TableBootstrap::initializeTableMenu(*handler1);
    mainMenu->run();
    delete handler1;
   /* int *a = new int();
    int *b = new int();
    mainMenu = CalculatorBootstrap::initializeCalculator(*a, *b);
    mainMenu->run();*/
    delete mainMenu;
    /*delete a;
    delete b;*/
    return 0;
}