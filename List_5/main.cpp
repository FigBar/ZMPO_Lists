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
    vector<Item *> firstItemTable{
            new Item("item 1", 5, 3),
            new Item("item 2", 12, 10),
            new Item("item 3", 10, 8),
            new Item("item 4", 7, 6),
            new Item("item 5", 1, 2),
            new Item("item 6", 11, 9),
            new Item("item 7", 100, 10),
            new Item("item 8", 45, 20)
    };
    Menu *mainMenu = KnapsackBootstrap::initializeKnapsackMenu(firstItemTable);
    mainMenu->run();

    delete mainMenu;


    return 0;
}