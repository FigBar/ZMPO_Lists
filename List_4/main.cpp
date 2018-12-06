#include <iostream>
#include "src/utils/Tools.h"
#include "src/Item.h"
#include "src/KnapsackProblem.h"
#include "src/GeneticAlgorithm.h"
#include <vector>

#define BEST_SOLUTION_PROMPT "#####BEST SOLUTION#####"
#define VALUE_SUM "Value sum: "
#define WEIGHT_SUM "Weight sum: "
using namespace std;

int main() {
    vector<Item *> firstItemTable{
            new Item("item 1", 7, 10),
            new Item("item 2", 5, 7),
            new Item("item 3", 4, 5),
            new Item("item 4", 3, 3),
            new Item("item 5", 6, 6),
            new Item("item 6", 7, 8),
            new Item("item 7", 2, 3),
            new Item("item 8", 1, 2),
    };

    double bagCapacity = 25;
    KnapsackProblem problem(firstItemTable, bagCapacity);
    GeneticAlgorithm algorithm(20, 0.75, 0.25, problem);

    Individual *bestSolution = algorithm.solveProblem(50);
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
    delete bestSolution;


    return 0;
}