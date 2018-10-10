//
// Created by fig_bar98 on 10.10.18.
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

bool Tools::yesOrNo() {
    string answer;
    char input;

    do {
        cout << "Do you want to create a parametrized object? " << " (Y/N)?: ";
        cin >> answer;

        input = answer.at(0);

        if (input == 'Y' || input == 'y') return true;
        if (input == 'N' || input == 'n') return false;
    } while (input == 'Y' || input == 'y' || input == 'N' || input == 'n');

    return false;
}

int Tools::provideAnInt(int lowerBound, int higherBound) {
    cout << "Provide an integer between " << lowerBound << " and " << higherBound << ": ";

    int answer;

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

int Tools::provideInt(int lowerBound, int higherBound) {

    int answer;
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

string Tools::provideString() {

    string givenName;
    cout << "Please provide a string." << endl;
    cin >> givenName;

    return givenName;
}