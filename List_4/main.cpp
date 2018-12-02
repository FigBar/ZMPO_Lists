#include <iostream>
#include "src/utils/Tools.h"
#include "src/Item.h"
#include "src/KnapsackProblem.h"
#include "src/GeneticAlgorithm.h"
#include <vector>
using namespace std;
int main() {
    vector<Item *> firstItemTable{
            new Item("item 1", 5, 3),
            new Item("item 2", 12, 10),
            new Item("item 3", 10, 8),
            new Item("item 4", 7, 6),
            new Item("item 5", 1, 2),
            new Item("item 6", 11, 9)
    };

    double bagCapacity = 20;
    KnapsackProblem problem(firstItemTable, bagCapacity);
    GeneticAlgorithm algorithm(4, 0.75, 0.25, problem);

    Individual *bestSolution = algorithm.solveProblem(500);
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


    return 0;
}