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
    Individual(KnapsackProblem &instOfProblem);

    Individual(KnapsackProblem &instOfProblem, int* genotype);

    Individual(const Individual& copyOther);

    ~Individual();

    double calcFitness();

    void mutate(int index);

    vector<Individual *>* cross(Individual &crossWith);

private:

    void generateGenotype();
    int *genotype;
    int nOfGenes;
    KnapsackProblem* problem;

};


#endif //LIST_4_INDIVIDUAL_H
