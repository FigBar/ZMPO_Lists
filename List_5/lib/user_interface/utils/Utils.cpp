//
// Created by fig_bar98 on 21.10.18.
//

#include "Utils.h"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

bool Utils::yesOrNo() {
    string answer;
    char input;

    do {
        cout << YES_OR_NO;
        cin >> answer;

        input = answer.at(0);

        if (input == 'Y' || input == 'y') return true;
        if (input == 'N' || input == 'n') return false;
    } while (input == 'Y' || input == 'y' || input == 'N' || input == 'n');

    return false;
}


int Utils::provideInt(int lowerBound, int higherBound) {

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

string Utils::provideString() {

    string givenName;
    cout << PROVIDE_STRING << endl;
    while(givenName.empty()) {
        getline(cin,  givenName);
    }
    return givenName;

}

