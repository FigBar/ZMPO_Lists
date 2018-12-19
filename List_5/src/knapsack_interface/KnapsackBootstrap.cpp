//
// Created by fig_bar98 on 13.12.18.
//

#include "KnapsackBootstrap.h"
#include "../../lib/user_interface/MenuCommand.h"
#include "KnapsackSolverCommand.h"
#include "PrintProblemCommand.h"
#include "AddItemCommand.h"
#include "DeleteItemCommand.h"

#define DOUBLE_COMMAND "double"

Menu *KnapsackBootstrap::initializeKnapsackMenu(KnapsackHandler *handler) {
    Menu* mainMenu = new Menu(MAIN_MENU, MAIN_COMMAND);

    MenuCommand* boolKnapsack = new MenuCommand(BOOL_NAME, BOOL_COMMAND, new KnapsackSolverCommand<bool>(handler));
    MenuCommand* intKnapsack = new MenuCommand(INTEGER_NAME, INTEGER_COMMAND, new KnapsackSolverCommand<int>(handler));
    MenuCommand* doubleKnapsack = new MenuCommand(DOUBLE_NAME, DOUBLE_COMMAND, new KnapsackSolverCommand<double>(handler));
    MenuCommand* printProblem = new MenuCommand(PRINT_ITEMS_NAME, PRINT_ITEMS_COMMAND, new PrintProblemCommand(handler));
    MenuCommand* addItem = new MenuCommand(ADD_ITEM_NAME, ADD_ITEM_COMMAND, new AddItemCommand(handler));
    MenuCommand* deleteItem = new MenuCommand(DELETE_ITEM_NAME, DELETE_ITEM_COMMAND, new DeleteItemCommand(handler));

    mainMenu->addMenuItem(boolKnapsack);
    mainMenu->addMenuItem(intKnapsack);
    mainMenu->addMenuItem(doubleKnapsack);
    mainMenu->addMenuItem(printProblem);
    mainMenu->addMenuItem(addItem);
    mainMenu->addMenuItem(deleteItem);
    return mainMenu;
}
