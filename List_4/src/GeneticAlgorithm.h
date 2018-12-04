//
// Created by fig_bar98 on 29.11.18.
//

#ifndef LIST_4_GENETICALGORITHM_H
#define LIST_4_GENETICALGORITHM_H


#define DEFAULT_POPSIZE 4

#define DEAFULT_CROSSPROB 0.75

#define DEFAULT_MUTPROB 0.25

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
    Individual *bestOfAll;

    vector<Individual *> *generatePopulation();

    Individual* generateIndividualsGenotype();

    void mutatePopulation(vector<Individual *> *population);

    void crossPopulation(Individual *fstParent, Individual *sndParent, vector<Individual *> *population);

    void destroyPopulation(vector<Individual*> *population);

    Individual *findTheBestFittingOne(vector<Individual*> *population);

    //Individual *findTheBestFittingOneAndDeleteOther(vector<Individual*> *population);

    Individual *selectBetterFitting(Individual *fst, Individual *snd);

    Individual *selectBetterFittingAndDeleteOther(Individual *fst, Individual *snd);

    Individual *getRandomIndividual(vector<Individual *> *population);

    bool doesActionAppear(double &probability);

    void setBestOfAll(vector<Individual *> *population);

};


#endif //LIST_4_GENETICALGORITHM_H
