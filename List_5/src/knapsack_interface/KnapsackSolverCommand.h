//
// Created by fig_bar98 on 13.12.18.
//

#ifndef LIST_5_KNAPSACKSOLVERCOMMAND_H
#define LIST_5_KNAPSACKSOLVERCOMMAND_H

#include <iostream>
#include <vector>
#include <tuple>
#include "../../lib/user_interface/Command.h"
#include "../knapsack_problem/Item.h"
#include "../../lib/user_interface/utils/Utils.h"
#include "../knapsack_problem/KnapsackProblem.h"
#include "../genetic_algorithm/GeneticAlgorithm.h"
#include "../knapsack_handler/KnapsackHandler.h"


#define BEST_SOLUTION_PROMPT "#####BEST SOLUTION#####"
#define VALUE_SUM "Value sum: "
#define WEIGHT_SUM "Weight sum: "
#define PART_TAKEN " part taken: "
#define CAPACITY_REQUEST "Please provide bag capacity: "
#define POP_SIZE_REQUEST "Please provide population size you want to generate: "
#define CROSS_PROB_REQUEST "Now provide crossing probability: "
#define MUT_PROB_REQUEST "Now provide mutation probability: "
#define EVAL_TIME_REQUEST "Finally provide algorithm evaluation time in seconds: "
using namespace std;

template<typename T>
class KnapsackSolverCommand : public Command {
public:
    explicit KnapsackSolverCommand(KnapsackHandler *handler1);

    virtual void runCommand();

private:
    KnapsackHandler *handler;

    void provideAlgorithmParameters(int &popSize, double &crossProb, double &mutProb, int &timeInSeconds);

    double provideBagCapacity();

};

template<typename T>
KnapsackSolverCommand<T>::KnapsackSolverCommand(KnapsackHandler *handler1) {
    this->handler = handler1;
}


template<typename T>
void KnapsackSolverCommand<T>::runCommand() {
    
    double bagCapacity = provideBagCapacity();
    KnapsackProblem<T> problem(*handler->getItems(), bagCapacity);
    int popSize = 0;
    double mutProb = 0;
    double crossProb = 0;
    int timeInSeconds = 0;
    provideAlgorithmParameters(popSize, crossProb, mutProb, timeInSeconds);
    GeneticAlgorithm<T> algorithm(popSize, crossProb, mutProb,
                                  problem);

    Individual<T> *bestSolution = algorithm.solveProblem(timeInSeconds);
    double solutionsWeight = 0;
    vector<tuple<Item*, T>> *solutionListOfItems = problem.decryptSolution(bestSolution->getGenotype(),
                                                                  bestSolution->getNOfGenes(), solutionsWeight);
    cout << endl << BEST_SOLUTION_PROMPT << endl;
    for (tuple<Item*, T> tuple1 : *solutionListOfItems) {
        cout << *get<0>(tuple1) << PART_TAKEN << get<1>(tuple1) << endl;
    }
    cout << VALUE_SUM << bestSolution->getFitness() << endl;
    cout << WEIGHT_SUM << solutionsWeight << endl << endl;
    delete solutionListOfItems;
}

template<typename T>
double KnapsackSolverCommand<T>::provideBagCapacity() {
    cout << CAPACITY_REQUEST;
    return Utils::provideNumber<double>(1, 100);
}

template<typename T>
void KnapsackSolverCommand<T>::provideAlgorithmParameters(int &popSize, double &crossProb, double &mutProb,
                                                          int &timeInSeconds) {
    cout << POP_SIZE_REQUEST << endl;
    popSize = Utils::provideNumber<int>(1, 20);
    cout << CROSS_PROB_REQUEST << endl;
    crossProb = Utils::provideNumber<double>(0, 1);
    cout << MUT_PROB_REQUEST << endl;
    mutProb = Utils::provideNumber<double>(0, 1);
    cout << EVAL_TIME_REQUEST << endl;
    timeInSeconds = Utils::provideNumber<int>(1, 5);
}


#endif //LIST_5_KNAPSACKSOLVERCOMMAND_H
