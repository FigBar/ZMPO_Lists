#include <iostream>
#include "src/knapsack_problem/Item.h"
#include "src/knapsack_problem/KnapsackProblem.h"
#include "src/genetic_algorithm/GeneticAlgorithm.h"
#include "src/genetic_algorithm/Individual.h"
#include "lib/user_interface/Menu.h"
#include "src/knapsack_interface/KnapsackBootstrap.h"
#include <vector>

using namespace std;

int main() {
    vector<Item *> *firstItemTable = new vector<Item *>();
    firstItemTable->push_back(new Item("item 0", 5, 3));
    firstItemTable->push_back(new Item("item 1", 12, 10));
    firstItemTable->push_back(new Item("item 2", 10, 8));
    firstItemTable->push_back(new Item("item 3", 7, 6));
    firstItemTable->push_back(new Item("item 4", 1, 2));
    firstItemTable->push_back(new Item("item 5", 11, 9));
    firstItemTable->push_back(new Item("item 6", 100, 10));
    firstItemTable->push_back(new Item("item 7", 45, 20));

    KnapsackHandler *handler = new KnapsackHandler(firstItemTable);
    Menu *mainMenu = KnapsackBootstrap::initializeKnapsackMenu(handler);
    mainMenu->run();

    delete mainMenu;
    delete handler;


    return 0;
}