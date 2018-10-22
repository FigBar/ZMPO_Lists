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
    Menu *mainMenu = new Menu("Main Menu", "main");
    Menu *creationMenu;
    creationMenu = new Menu("Create Tables", "create");
    creationMenu->addMenuItem(new MenuCommand("Create one Table", "one", new createSingleTable(handler1)));
    creationMenu->addMenuItem(
            new MenuCommand("Create multiple Tables", "multiple", new createMultipleTables(handler1)));
    creationMenu->addMenuItem(new MenuCommand("Clone a Table and append it", "clone", new CloneTable(handler1)));

    mainMenu->addMenuItem(creationMenu);

    Menu *changeMenu;
    changeMenu = new Menu("change Tables", "change");
    changeMenu->addMenuItem(new MenuCommand("Set Name", "sName", new SetName(handler1)));
    changeMenu->addMenuItem(new MenuCommand("Set Size", "sSize", new SetSize(handler1)));
    changeMenu->addMenuItem(new MenuCommand("Insert Number", "insert", new InsertNumber(handler1)));
    //changeMenu->addMenuItem(new MenuCommand("Default", "Default", new Command));

    mainMenu->addMenuItem(changeMenu);

    Menu *removeMenu;
    removeMenu = new Menu("remove Tables", "remove");
    removeMenu->addMenuItem(new MenuCommand("Delete one", "delete_one", new DeleteOne(handler1)));
    removeMenu->addMenuItem(new MenuCommand("Delete all", "delete_all", new DeleteAll(handler1)));
    mainMenu->addMenuItem(removeMenu);

    Menu *printMenu;
    printMenu = new Menu("print Tables", "print");
    printMenu->addMenuItem(new MenuCommand("Print one", "print_one", new PrintTable(handler1)));
    printMenu->addMenuItem(new MenuCommand("Print all", "print_all", new PrintAll(handler1)));
    mainMenu->addMenuItem(printMenu);

    return mainMenu;
}
