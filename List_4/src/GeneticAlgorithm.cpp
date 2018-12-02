//
// Created by fig_bar98 on 29.11.18.
//

#include "GeneticAlgorithm.h"
#include "utils/Tools.h"
#include <iostream>

GeneticAlgorithm::GeneticAlgorithm(int popSize, double crossProb, double mutProb, KnapsackProblem &problem) {
    this->popSize = popSize;
    this->crossProb = crossProb;
    this->mutProb = mutProb;
    this->nOfItems = problem.getNOfItems();
    this->problem = &problem;
    this->bestOfAll = nullptr;
}

GeneticAlgorithm::GeneticAlgorithm(GeneticAlgorithm &algorithm) {
    this->popSize = algorithm.popSize;
    this->crossProb = algorithm.crossProb;
    this->mutProb = algorithm.mutProb;
    this->nOfItems = algorithm.problem->getNOfItems();
    this->problem = algorithm.problem;
    this->bestOfAll = algorithm.bestOfAll;
}

GeneticAlgorithm::~GeneticAlgorithm(){
    delete bestOfAll;
};

Individual *GeneticAlgorithm::solveProblem(int nOfIterations) {
    vector<Individual *> *population = generatePopulation();

    for (int i = 0; i < nOfIterations; ++i) {

        vector<Individual *> *nextGeneration = new vector<Individual *>();
        while (nextGeneration->size() < popSize) {
            Individual *fstParent = selectBetterFitting(getRandomIndividual(population), getRandomIndividual(population));
            Individual *sndParent = selectBetterFitting(getRandomIndividual(population), getRandomIndividual(population));
            crossPopulation(fstParent, sndParent, nextGeneration);
        }
        mutatePopulation(nextGeneration);
        if (findTheBestFittingOne(population)->getFitness() >= findTheBestFittingOne(nextGeneration)->getFitness()) {
            destroyPopulation(nextGeneration);
        } else {
            destroyPopulation(population);
            population = nextGeneration;
        }
        //TODO delete it, only to check how it works
        cout << "iteration: " << i << " ||Best fitness: " << findTheBestFittingOne(population)->getFitness()
             << endl;

    }
    bestOfAll = new Individual(*findTheBestFittingOne(population));
    destroyPopulation(population);
    return bestOfAll;
}

vector<Individual *> *GeneticAlgorithm::generatePopulation() {
    vector<Individual *> *population = new vector<Individual *>();
    for (int i = 0; i < popSize; ++i) {
        population->push_back(generateIndividualsGenotype());
    }
    return population;
}

Individual *GeneticAlgorithm::generateIndividualsGenotype() {
    int *generatedGenotype = new int[problem->getNOfItems()];

    for (int i = 0; i < problem->getNOfItems(); ++i) {
        generatedGenotype[i] = Tools::generateRandomNumber(0, 1);
    }
    return new Individual(*problem, generatedGenotype);
}

void GeneticAlgorithm::crossPopulation(Individual *fstParent, Individual *sndParent, vector<Individual *> *population) {
    if (doesActionAppear(crossProb)) { //cross parents and add their children to population
        vector<Individual *> *offspring = fstParent->cross(*sndParent);
        Individual *fstChild = offspring->at(0);
        Individual *sndChild = offspring->at(1);
        delete offspring;

        if (population->size() + 1 < popSize) {
            population->push_back(fstChild);
            population->push_back(sndChild);
        } else {
            population->push_back(selectBetterFittingAndDeleteOther(fstChild, sndChild));
        }
    } else { // do not cross just add parents to new population
        if (population->size() + 1 < popSize) {
            population->push_back(new Individual(*fstParent));
            population->push_back(new Individual(*sndParent));
        } else {
            Individual *betterFitting = (fstParent->getFitness() > sndParent->getFitness()) ? fstParent : sndParent;
            population->push_back(new Individual(*betterFitting));
        }
    }
}

void GeneticAlgorithm::mutatePopulation(vector<Individual *> *population) {
    for (Individual *individual : *population) {
        if (doesActionAppear(mutProb)) {
            for (int i = 0; i < nOfItems; ++i) {
                if (doesActionAppear(mutProb))
                    individual->mutate(i);
            }
        }
    }
}

void GeneticAlgorithm::destroyPopulation(vector<Individual *> *population) {
    for (int i = 0; i < population->size(); ++i) {
        delete population->at(i);
    }
    delete population;
}

Individual *GeneticAlgorithm::findTheBestFittingOne(vector<Individual *> *population) {
    Individual *bestIndividual = population->at(0);
    for (int i = 1; i < population->size(); ++i) {
        if (population->at(i)->getFitness() > bestIndividual->getFitness())
            bestIndividual = population->at(i);
    }
    return bestIndividual;
}


Individual *GeneticAlgorithm::selectBetterFittingAndDeleteOther(Individual *fst, Individual *snd) {
    if (fst->getFitness() > snd->getFitness()) {
        delete snd;
        return fst;
    } else {
        delete fst;
        return snd;
    }
}

Individual *GeneticAlgorithm::selectBetterFitting(Individual *fst, Individual *snd) {
    return (fst->getFitness() > snd->getFitness()) ? fst : snd;
}

Individual *GeneticAlgorithm::getRandomIndividual(vector<Individual *> *population) {
    return population->at((unsigned long) Tools::generateRandomNumber(0, (int) population->size() - 1));
}


bool GeneticAlgorithm::doesActionAppear(double &probability) {
    double randomProb = ((double) Tools::generateRandomNumber(0, 100) / 100.0);
    return randomProb < probability;
}

/*void GeneticAlgorithm::setBestOfAll(vector<Individual *> *population) {
    int index;
    Individual *contender = findTheBestFittingOne(population, index);
    if (bestOfAll) {
        Individual *newBest = selectBetterFitting(bestOfAll, contender);
        if (bestOfAll != newBest) {
            delete bestOfAll;
            bestOfAll = new Individual(*newBest);
        }
    } else {
        delete bestOfAll;
        bestOfAll = new Individual(*contender);
    }
}*/
