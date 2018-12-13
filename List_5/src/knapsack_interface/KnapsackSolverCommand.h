//
// Created by fig_bar98 on 13.12.18.
//

#ifndef LIST_5_KNAPSACKSOLVERCOMMAND_H
#define LIST_5_KNAPSACKSOLVERCOMMAND_H

#include <iostream>
#include <vector>
#include "../../lib/user_interface/Command.h"
#include "../knapsack_problem/Item.h"
#include "../../lib/user_interface/utils/Utils.h"
#include "../knapsack_problem/KnapsackProblem.h"
#include "../genetic_algorithm/GeneticAlgorithm.h"


#define BEST_SOLUTION_PROMPT "#####BEST SOLUTION#####"
#define VALUE_SUM "Value sum: "
#define WEIGHT_SUM "Weight sum: "

using namespace std;

template<typename T>
class KnapsackSolverCommand : public Command {
public:
    KnapsackSolverCommand(vector<Item *> listOfItems);

    virtual void runCommand();

private:
    vector<Item *> listOfItems;

    void printListOfItems();

    void provideAlgorithmParameters(int &popSize, double &crossProb, double &mutProb, int &timeInSeconds);

};

template<typename T>
KnapsackSolverCommand<T>::KnapsackSolverCommand(vector<Item *> listOfItems) {
    for (int i = 0; i < listOfItems.size(); ++i) {
        this->listOfItems.push_back(listOfItems.at(i));
    }
}

template<typename T>
void KnapsackSolverCommand<T>::runCommand() {
    printListOfItems();
    double bagCapacity = 34;
    KnapsackProblem<T> problem(this->listOfItems, bagCapacity);
    int popSize = 0;
    double mutProb = 0;
    double crossProb = 0;
    int timeInSeconds = 0;
    provideAlgorithmParameters(popSize, crossProb, mutProb, timeInSeconds);
    GeneticAlgorithm<T> algorithm(popSize, crossProb, mutProb,
                                  problem); //best solution: items 1,7,8; value: 150; weight: 33

    Individual<T> *bestSolution = algorithm.solveProblem(timeInSeconds);
    double solutionsWeight = 0;
    vector<Item *> *solutionListOfItems = problem.decryptSolution(bestSolution->getGenotype(),
                                                                  bestSolution->getNOfGenes(), solutionsWeight);
    cout << endl << BEST_SOLUTION_PROMPT << endl;
    for (Item *item : *solutionListOfItems) {
        cout << *item;
    }
    cout << VALUE_SUM << bestSolution->getFitness() << endl;
    cout << WEIGHT_SUM << solutionsWeight << endl;

    delete solutionListOfItems;
}

template<typename T>
void KnapsackSolverCommand<T>::printListOfItems() {
    cout << "###ITEM_LIST###" << endl;
    for (int i = 0; i < listOfItems.size(); ++i) {
        cout << *(listOfItems.at(i));
    }
    cout << "######################################################" << endl;
}

template<typename T>
void KnapsackSolverCommand<T>::provideAlgorithmParameters(int &popSize, double &crossProb, double &mutProb,
                                                          int &timeInSeconds) {
    cout << "Please provide population size you want to generate: " << endl;
    popSize = Utils::provideNumber<int>(1, 20);
    cout << "Now provide crossing probability: " << endl;
    crossProb = Utils::provideNumber<double>(0, 1);
    cout << "Now provide mutation probability: " << endl;
    mutProb = Utils::provideNumber<double>(0, 1);
    cout << "Finally provide algorithm evaluation time in seconds: " << endl;
    timeInSeconds = Utils::provideNumber<int>(1, 5);
}


#endif //LIST_5_KNAPSACKSOLVERCOMMAND_H
