//
// Created by fig_bar98 on 29.11.18.
//

#include "GeneticAlgorithm.h"
#include "utils/Tools.h"

GeneticAlgorithm::GeneticAlgorithm(int popSize, double crossProb, double mutProb, KnapsackProblem &problem) {
    this->popSize = popSize;
    this->crossProb = crossProb;
    this->mutProb = mutProb;
    this->nOfItems = problem.getNOfItems();
    this->problem = &problem;
}

GeneticAlgorithm::GeneticAlgorithm(GeneticAlgorithm &algorithm) {
    this->popSize = algorithm.popSize;
    this->crossProb = algorithm.crossProb;
    this->mutProb = algorithm.mutProb;
    this->nOfItems = algorithm.problem->getNOfItems();
    this->problem = algorithm.problem;
}

GeneticAlgorithm::~GeneticAlgorithm() {
//TODO implement this shit
}

Individual *GeneticAlgorithm::solveProblem(int nOfIterations) {
    vector<Individual *> *population = generatePopulation();

    for (int i = 0; i < nOfIterations ; ++i) {

    }
    return nullptr;
}

vector<Individual *> *GeneticAlgorithm::generatePopulation() {
    vector<Individual *> *population = new vector<Individual *>();
    for (int i = 0; i < popSize; ++i) {
        population->push_back(new Individual(*problem));
    }
    return population;
}

void GeneticAlgorithm::mutatePopulation(vector<Individual *> *population) {
    for (Individual *individual : *population){
        if(doesMutationAppear()){
            for (int i = 0; i < nOfItems ; ++i) {
                if(doesMutationAppear())
                    individual->mutate(i);
            }
        }
    }
}

bool GeneticAlgorithm::doesMutationAppear() {
    double randomProb = ((double)Tools::generateRandomNumber(0, 100)/100.0);
    return randomProb < mutProb;
}
