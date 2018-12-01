//
// Created by fig_bar98 on 28.10.18.
//

#include "CalculatorBootstrap.h"
#include "../../../lib/user_interface/MenuCommand.h"
#include "../commands/ChangeA.h"
#include "../commands/ChangeB.h"
#include "../commands/Add.h"
#include "../commands/Substract.h"
#include "../commands/Reset.h"

Menu *CalculatorBootstrap::initializeCalculator(MenuAnalyzer &analyzer, int &a, int &b) {
    Menu *mainMenu = new Menu(MAIN_MENU, MAIN_COMMAND, analyzer);
    analyzer.setMainMenu(*mainMenu);
    mainMenu->addMenuItem(new MenuCommand("Zmien liczbe A", "zma", new ChangeA(a, b), "Zmienia wartosc liczby A"));
    mainMenu->addMenuItem(new MenuCommand("Zmien liczbe B", "zmb", new ChangeB(a,b), "Zmienia wartosc liczby B"));

    Menu *opMenu = new Menu("Operacje", "op", analyzer);
    opMenu->addMenuItem(new MenuCommand("Dodaj", "dod", new Add(a,b), "Dodaje liczby a i b"));
    opMenu->addMenuItem(new MenuCommand("Odejmij", "ode", new Substract(a,b), "Odejmij liczby a i b"));
    opMenu->addMenuItem(new MenuCommand("default command", "defcom", new Command()));

    mainMenu->addMenuItem(opMenu);
    mainMenu->addMenuItem(new MenuCommand("Reset", "res", new Reset(a,b)));

    return mainMenu;
}
