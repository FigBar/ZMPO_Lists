//
// Created by Bartosz Figiel on 19.10.2018.
//

#ifndef LIST_2_TOOLS_H
#define LIST_2_TOOLS_H
#include<string>
using namespace std;

class Tools {
public:

    static bool indexCheck(int index, int start, int end);

    static bool initializeWithZeros(int *table, int start, int end);

};


#endif //LIST_2_TOOLS_H
