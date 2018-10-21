//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_UTILS_H
#define LIST_2_UTILS_H

#include <string>

using namespace std;


class Utils {

public:
    static bool yesOrNo();

    static int provideAnInt(int lowerBound, int higherBound);

    static int provideInt(int lowerBound, int higherBound);

    static string provideString();
};


#endif //LIST_2_UTILS_H
