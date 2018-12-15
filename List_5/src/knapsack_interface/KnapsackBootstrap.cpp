//
// Created by fig_bar98 on 13.12.18.
//

#include "KnapsackBootstrap.h"
#include "../../lib/user_interface/MenuCommand.h"
#include "KnapsackSolverCommand.h"
#include "PrintProblemCommand.h"
#include "AddItemCommand.h"
#include "DeleteItemCommand.h"

Menu *KnapsackBootstrap::initializeKnapsackMenu(KnapsackHandler *handler) {
    Menu* mainMenu = new Menu("Main Menu", "main");

    MenuCommand* boolKnapsack = new MenuCommand("solve boolean knapsack problem", "bool", new KnapsackSolverCommand<bool>(handler));
    MenuCommand* intKnapsack = new MenuCommand("solve integer knapsack problem", "int", new KnapsackSolverCommand<int>(handler));
    MenuCommand* doubleKnapsack = new MenuCommand("solve double knapsack problem", "double", new KnapsackSolverCommand<double>(handler));
    MenuCommand* printProblem = new MenuCommand("print list of problem's items", "print", new PrintProblemCommand(handler));
    MenuCommand* addItem = new MenuCommand("add item to problem", "add", new AddItemCommand(handler));
    MenuCommand* deleteItem = new MenuCommand("delete item from problem", "delete", new DeleteItemCommand(handler));

    mainMenu->addMenuItem(boolKnapsack);
    mainMenu->addMenuItem(intKnapsack);
    mainMenu->addMenuItem(doubleKnapsack);
    mainMenu->addMenuItem(printProblem);
    mainMenu->addMenuItem(addItem);
    mainMenu->addMenuItem(deleteItem);
    return mainMenu;
}
