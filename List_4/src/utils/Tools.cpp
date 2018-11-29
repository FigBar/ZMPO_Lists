//
// Created by fig_bar98 on 29.11.18.
//

#include "Tools.h"
#include <random>
using namespace std;


int Tools::generateRandomNumber(int lowerBound, int upperBound) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> generate(lowerBound, upperBound);
    return generate(gen);
}
