//
// Created by fig_bar98 on 22.10.18.
//

#include "Initializer.h"
#include "MenuCommand.h"
#include "Command_Package/List_1_Commands_Package/createSingleTable.h"
#include "Command_Package/List_1_Commands_Package/createMultipleTables.h"
#include "Command_Package/List_1_Commands_Package/CloneTable.h"
#include "Command_Package/List_1_Commands_Package/SetName.h"
#include "Command_Package/List_1_Commands_Package/SetSize.h"
#include "Command_Package/List_1_Commands_Package/InsertNumber.h"
#include "Command_Package/List_1_Commands_Package/DeleteOne.h"
#include "Command_Package/List_1_Commands_Package/DeleteAll.h"
#include "Command_Package/List_1_Commands_Package/PrintTable.h"
#include "Command_Package/List_1_Commands_Package/PrintAll.h"

Menu *Initializer::initialize(TableHandler &handler1) {
    Menu *mainMenu = new Menu(MAIN_MENU, MAIN_COMMAND);
    Menu *creationMenu;
    creationMenu = new Menu(CREATION_MENU, CREATION_COMMAND);
    creationMenu->addMenuItem(new MenuCommand(CREATE_1, CR_1_COM, new createSingleTable(handler1)));
    creationMenu->addMenuItem(
            new MenuCommand(CREATE_2, CR_2_COM, new createMultipleTables(handler1)));
    creationMenu->addMenuItem(new MenuCommand(CREATE_3, CR_3_COM, new CloneTable(handler1)));

    mainMenu->addMenuItem(creationMenu);

    Menu *changeMenu;
    changeMenu = new Menu(CHANGE_MENU, CHANGE_COMMAND);
    changeMenu->addMenuItem(new MenuCommand(CHANGE_1, CH_1_COM, new SetName(handler1)));
    changeMenu->addMenuItem(new MenuCommand(CHANGE_2, CH_2_COM, new SetSize(handler1)));
    changeMenu->addMenuItem(new MenuCommand(CHANGE_3, CH_3_COM, new InsertNumber(handler1)));


    mainMenu->addMenuItem(changeMenu);

    Menu *deleteMenu;
    deleteMenu = new Menu(DELETE_MENU, DELETE_COMMAND);
    deleteMenu->addMenuItem(new MenuCommand(DELETE_1, DE_1_COM, new DeleteOne(handler1)));
    deleteMenu->addMenuItem(new MenuCommand(DELETE_2, DE_2_COM, new DeleteAll(handler1)));
    mainMenu->addMenuItem(deleteMenu);

    Menu *printMenu;
    printMenu = new Menu(PRINT_MENU, PRINT_COMMAND);
    printMenu->addMenuItem(new MenuCommand(PRINT_1, PR_1_COM, new PrintTable(handler1)));
    printMenu->addMenuItem(new MenuCommand(PRINT_2, PR_2_COM, new PrintAll(handler1)));
    mainMenu->addMenuItem(printMenu);

    return mainMenu;
}
