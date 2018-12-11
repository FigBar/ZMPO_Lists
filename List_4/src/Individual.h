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

    Individual(Individual& copyOther);

    ~Individual();



    void mutate(int index);

    vector<Individual *>* cross(Individual &crossWith);

    double getFitness() const;

    int *getGenotype() const;

    int getNOfGenes() const;

private:

    void calcFitness();

    int *genotype;
    int nOfGenes;
    double fitness;
    KnapsackProblem* problem;

};


#endif //LIST_4_INDIVIDUAL_H
