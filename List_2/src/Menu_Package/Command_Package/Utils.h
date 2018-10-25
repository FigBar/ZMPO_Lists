//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_UTILS_H
#define LIST_2_UTILS_H

#define YES_OR_NO "Do you want to create a parametrized object? (Y/N)?: "

#define PROVIDE_INT "Provide an integer between "

#define PROVIDE_STRING "Please provide a string."

#include <string>

using namespace std;


class Utils {

public:
    static bool yesOrNo();

    static int provideAnInt(int lowerBound, int higherBound);

    static int provideInt(int lowerBound, int higherBound);

    static string provideString();

    static string provideCommand();
};


#endif //LIST_2_UTILS_H
