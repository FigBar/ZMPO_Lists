//
// Created by fig_bar98 on 29.11.18.
//

#ifndef LIST_4_GENETICALGORITHM_H
#define LIST_4_GENETICALGORITHM_H


#include "KnapsackProblem.h"
#include "Individual.h"

class GeneticAlgorithm {
public:
    GeneticAlgorithm(int popSize, double crossProb, double mutProb, KnapsackProblem &problem);

    GeneticAlgorithm(GeneticAlgorithm &algorithm);

    ~GeneticAlgorithm();

    Individual *solveProblem(int nOfIterations);

private:
    int popSize;
    double crossProb;
    double mutProb;
    int nOfItems;
    KnapsackProblem *problem;

    vector<Individual *> *generatePopulation();

    void mutatePopulation(vector<Individual *> *population);

    void crossPopulation(Individual *fstParent, Individual *sndParent, vector<Individual *> *population);

    Individual *selectBetterFitting(Individual *fst, Individual *snd);

    Individual *selectBetterFittingAndDeleteOther(Individual *fst, Individual *snd);

    Individual *getRandomIndividual(vector<Individual *> *population);

    bool doesActionAppear(double &probability);

};


#endif //LIST_4_GENETICALGORITHM_H
