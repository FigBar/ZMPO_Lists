//
// Created by fig_bar98 on 05.11.18.
//
#include <string>

#ifndef LIST_3_STRINGVALIDATOR_H
#define LIST_3_STRINGVALIDATOR_H
using namespace std;

class StringValidator {

    static void validateMenuCommand(string toValidate, char &errorCode, int &errorIndex, int &currentIndex, bool &correctness);

    static void validateNameAndCommand(string &toValidate, char &errorCode, int &errorIndex, int &currentIndex, bool &correctness);

    static bool checkSymbolInString(string &toValidate, int index, char compareWith, char &errorCode, bool &correctness);

    static int findIndexOfMissingChar(string &menuSave);

    static int findClosingChar(string &menuTree, char opening);
};


#endif //LIST_3_STRINGVALIDATOR_H
