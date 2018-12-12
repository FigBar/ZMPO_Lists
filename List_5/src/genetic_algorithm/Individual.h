//
// Created by fig_bar98 on 22.11.18.
//

#ifndef LIST_4_INDIVIDUAL_H
#define LIST_4_INDIVIDUAL_H

#include <vector>
#include "../knapsack_problem/KnapsackProblem.h"


using namespace std;

class Individual {

public:
    Individual(KnapsackProblem &instOfProblem, double mutProb);

    Individual(KnapsackProblem &instOfProblem, int *genotype, double mutProb);

    Individual(Individual &copyOther);

    ~Individual();

    void operator++(int);

    Individual *operator+(Individual &crossWith);

    double getFitness() const;

    int *getGenotype() const;

    int getNOfGenes() const;

private:
    double mutProb;
    int *genotype;
    int nOfGenes;
    double fitness;
    KnapsackProblem *problem;

    void mutate();

    vector<Individual *> *cross(Individual &crossWith);

    void calcFitness();

};


#endif //LIST_4_INDIVIDUAL_H
