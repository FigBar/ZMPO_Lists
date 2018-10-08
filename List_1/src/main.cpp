#include <iostream>
#include "CRun.h"
using namespace std;
int main() {

    CRun *runner;
    runner = new CRun();

    runner->start();

    delete runner;


    return 0;
}