#include "GeneticAlgorithm.h"

template<>
Individual<bool> *GeneticAlgorithm<bool>::generateIndividualsGenotype() {
    bool *generatedGenotype = new bool[problem->getNOfItems()];

    for (int i = 0; i < problem->getNOfItems(); ++i) {
        if (Tools::generateRandomNumber(0, 1))
            generatedGenotype[i] = true;
        else
            generatedGenotype[i] = false;
    }
    return new Individual<bool>(*problem, generatedGenotype, mutProb);
}
