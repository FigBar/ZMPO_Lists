//
// Created by fig_bar98 on 28.10.18.
//

#include "TableBootstrap.h"
#include "../../../../lib/user_interface/MenuCommand.h"
#include "../commands/createSingleTable.h"
#include "../commands/createMultipleTables.h"
#include "../commands/CloneTable.h"
#include "../commands/SetName.h"
#include "../commands/SetSize.h"
#include "../commands/InsertNumber.h"
#include "../commands/DeleteOne.h"
#include "../commands/DeleteAll.h"
#include "../commands/PrintTable.h"
#include "../commands/PrintAll.h"

Menu *TableBootstrap::initializeTableMenu(MenuAnalyzer &analyzer, TableHandler &handler1) {

    Menu *mainMenu = new Menu(MAIN_MENU, MAIN_COMMAND, analyzer);
    analyzer.setMainMenu(*mainMenu);
    Menu *creationMenu;
    creationMenu = new Menu(CREATION_MENU, CREATION_COMMAND, analyzer);
    creationMenu->addMenuItem(new MenuCommand(CREATE_1, CR_1_COM, new createSingleTable(handler1)));
    creationMenu->addMenuItem(
            new MenuCommand(CREATE_2, CR_2_COM, new createMultipleTables(handler1)));
    creationMenu->addMenuItem(new MenuCommand(CREATE_3, CR_3_COM, new CloneTable(handler1)));

    mainMenu->addMenuItem(creationMenu);

    Menu *changeMenu;
    changeMenu = new Menu(CHANGE_MENU, CHANGE_COMMAND, analyzer);
    changeMenu->addMenuItem(new MenuCommand(CHANGE_1, CH_1_COM, new SetName(handler1)));
    changeMenu->addMenuItem(new MenuCommand(CHANGE_2, CH_2_COM, new SetSize(handler1)));
    changeMenu->addMenuItem(new MenuCommand(CHANGE_3, CH_3_COM, new InsertNumber(handler1)));


    mainMenu->addMenuItem(changeMenu);

    Menu *deleteMenu;
    deleteMenu = new Menu(DELETE_MENU, DELETE_COMMAND, analyzer);
    deleteMenu->addMenuItem(new MenuCommand(DELETE_1, DE_1_COM, new DeleteOne(handler1)));
    deleteMenu->addMenuItem(new MenuCommand(DELETE_2, DE_2_COM, new DeleteAll(handler1)));
    mainMenu->addMenuItem(deleteMenu);

    Menu *printMenu;
    printMenu = new Menu(PRINT_MENU, PRINT_COMMAND, analyzer);
    printMenu->addMenuItem(new MenuCommand(PRINT_1, PR_1_COM, new PrintTable(handler1)));
    printMenu->addMenuItem(new MenuCommand(PRINT_2, PR_2_COM, new PrintAll(handler1)));
    mainMenu->addMenuItem(printMenu);

    return mainMenu;
}
