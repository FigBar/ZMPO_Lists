#include <iostream>
#include "src/utils/Tools.h"
#include "src/Item.h"
#include "src/KnapsackProblem.h"
#include "src/GeneticAlgorithm.h"
#include <vector>
using namespace std;
int main() {
    vector<Item *> firstItemTable{
            new Item("item 1", 4, 2),
            new Item("item 2", 1, 9),
            new Item("item 3", 10, 1),
            new Item("item 4", 12, 8),
            new Item("item 5", 13, 4),
            new Item("item 6", 100, 20),
            new Item("item 7", 19, 4),
            new Item("item 8", 13, 32),
            new Item("item 9", 22, 6),
            new Item("item 10", 8, 3)
    };

    double bagCapacity = 34;
    KnapsackProblem problem(firstItemTable, bagCapacity);
    GeneticAlgorithm algorithm(4, 0.50, 0.20, problem);

    Individual *bestSolution = algorithm.solveProblem(1000);
    vector <Item*> *solutionListOfItems = problem.decryptSolution(bestSolution->getGenotype(), bestSolution->getNOfGenes());

    double sumOfWeights = 0;
    cout << endl << "#####BEST SOLUTION#####" << endl;
    for (Item *item : *solutionListOfItems){
        cout << *item;
        sumOfWeights += item->getWeight();
    }
    cout << "Value sum: " << bestSolution->getFitness() << endl;
    cout << "Weight sum: " << sumOfWeights << endl;

    for(Item *item : firstItemTable)
        delete item;

    delete solutionListOfItems;
    delete bestSolution;


    return 0;
}