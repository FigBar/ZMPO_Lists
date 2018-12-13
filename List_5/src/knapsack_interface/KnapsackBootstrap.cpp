//
// Created by fig_bar98 on 13.12.18.
//

#include "KnapsackBootstrap.h"
#include "../../lib/user_interface/MenuCommand.h"
#include "KnapsackSolverCommand.h"

Menu *KnapsackBootstrap::initializeKnapsackMenu(vector<Item *> listOfItems) {
    Menu* mainMenu = new Menu("Main Menu", "main");

    MenuCommand* boolKnapsack = new MenuCommand("BooleanKnapsack", "bool", new KnapsackSolverCommand<bool>(listOfItems));
    MenuCommand* intKnapsack = new MenuCommand("IntegerKnapsack", "int", new KnapsackSolverCommand<int>(listOfItems));
    MenuCommand* doubleKnapsack = new MenuCommand("DoubleKnapsack", "double", new KnapsackSolverCommand<double>(listOfItems));

    mainMenu->addMenuItem(boolKnapsack);
    mainMenu->addMenuItem(intKnapsack);
    mainMenu->addMenuItem(doubleKnapsack);
    return mainMenu;
}
