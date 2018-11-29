#include <iostream>
#include "src/utils/Tools.h"
#include "src/Item.h"
#include "src/KnapsackProblem.h"
#include "src/GeneticAlgorithm.h"
#include <vector>
using namespace std;
int main() {
    vector<Item *> firstItemTable {
        new Item("item 0", 5, 4),
        new Item("item 1", 1, 1),
        new Item("item 2", 4, 3),
        new Item("item 3", 3, 2)
    };
    double bagCapacity = 5;
    KnapsackProblem problem(firstItemTable, bagCapacity);
    GeneticAlgorithm algorithm(4, 0.70, 0.20, problem);

    Individual *bestSolution = algorithm.solveProblem(10);
    vector <Item*> *solutionListOfItems = problem.decryptSolution(bestSolution->getGenotype(), bestSolution->getNOfGenes());

    double sumOfWeights = 0;
    cout << "#####BEST SOLUTION#####" << endl;
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