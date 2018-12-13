//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_UTILS_H
#define LIST_2_UTILS_H

#define YES_OR_NO "Do you want to create a parametrized object? (Y/N)?: "

#define PROVIDE_INT "Provide an integer between "

#define PROVIDE_STRING "Please provide a string."

#include <string>
#include <iostream>
#include <sstream>

using namespace std;


class Utils {

public:
    static bool yesOrNo();

    template <typename T>
    static T provideNumber(int lowerBound, int higherBound);

    static int provideInt(int lowerBound, int higherBound);

    static string provideString();

};

template <typename T>
T Utils::provideNumber(int lowerBound, int higherBound) {
    cout << PROVIDE_INT << lowerBound << " and " << higherBound << ": ";

    T answer;

    bool valid;
    do{
        string string1;
        stringstream stringstream1;
        getline(cin, string1);
        stringstream1 << string1;
        valid = !(stringstream1 >> answer);
    } while (valid || answer < lowerBound || higherBound < answer);
    return answer;
}
#endif //LIST_2_UTILS_H
