//
// Created by Bartosz Figiel on 19.10.2018.
//



#include <iostream>
#include <sstream>
#include "Tools.h"

using namespace std;

bool Tools::indexCheck(int index, int start, int end) {
    return (index >= start && index < end);
}

bool Tools::initializeWithZeros(int *table, int start, int end) {
    if (0 <= start && start < end) {
        for (int i = start; i < end; ++i) {
            table[i] = 0;
        }
        return true;
    } else
        return false;
}

