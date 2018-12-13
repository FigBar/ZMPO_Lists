#include <iostream>
#include "src/knapsack_problem/Item.h"
#include "src/knapsack_problem/KnapsackProblem.h"
#include "src/genetic_algorithm/GeneticAlgorithm.h"
#include "src/genetic_algorithm/Individual.h"
#include <vector>

#define BEST_SOLUTION_PROMPT "#####BEST SOLUTION#####"
#define VALUE_SUM "Value sum: "
#define WEIGHT_SUM "Weight sum: "
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

    double bagCapacity = 34;
    KnapsackProblem problem(firstItemTable, bagCapacity);
    GeneticAlgorithm algorithm(4, 0.75, 0.25, problem); //best solution: items 1,7,8; value: 150; weight: 33

    Individual *bestSolution = algorithm.solveProblem(1);
    vector<Item *> *solutionListOfItems = problem.decryptSolution(bestSolution->getGenotype(),
                                                                  bestSolution->getNOfGenes());

    double sumOfWeights = 0;
    cout << endl << BEST_SOLUTION_PROMPT << endl;
    for (Item *item : *solutionListOfItems) {
        cout << *item;
        sumOfWeights += item->getWeight();
    }
    cout << VALUE_SUM << bestSolution->getFitness() << endl;
    cout << WEIGHT_SUM << sumOfWeights << endl;

    for (Item *item : firstItemTable)
        delete item;

    delete solutionListOfItems;


    return 0;
}