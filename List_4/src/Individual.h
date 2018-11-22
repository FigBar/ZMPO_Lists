//
// Created by fig_bar98 on 22.11.18.
//

#ifndef LIST_4_INDIVIDUAL_H
#define LIST_4_INDIVIDUAL_H

#include <vector>
#include "KnapsackProblem.h"

using namespace std;

class Individual {

public:
    Individual(const KnapsackProblem &instOfProblem);

    Individual(const Individual& copyOther);

    ~Individual();

    int calcFitness();

    void mutate(const double &mutProb);

    vector<Individual *> cross(Individual &crossWith);

private:
    int *genotype;
    int nOfGenes;
    double fitness;
    KnapsackProblem* problem;

};


#endif //LIST_4_INDIVIDUAL_H
