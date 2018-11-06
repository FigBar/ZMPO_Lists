//
// Created by fig_bar98 on 05.11.18.
//
#include <string>

#ifndef LIST_3_STRINGVALIDATOR_H
#define LIST_3_STRINGVALIDATOR_H
#define OP_PARENTHESIS1 '('
#define CLS_PARENTHESIS1 ')'
#define EMPTY_STRING ""
#define SEMICOLON1 ';'
#define OP_SQR_BRACKET1 '['
#define COMA1 ','
#define CLS_SQR_BRACKET1 ']'
#define APOSTROPHE1 '\''
#define DEFAULT_ERROR_CODE '~'
using namespace std;

class StringValidator {

public:
    static void validateMenu(string toValidate, char &errorCode, int &errorIndex, int &currentIndex, bool &correctness);

    static void validateMenuCommand(string toValidate, char &errorCode, int &errorIndex, int &currentIndex, bool &correctness);

    static void validateNameAndCommand(string &toValidate, char &errorCode, int &errorIndex, int &currentIndex, bool &correctness);

    static bool checkSymbolInString(string &toValidate, int index, char compareWith, char &errorCode, bool &correctness);

    static int findIndexOfMissingChar(string &menuSave);

    static int findClosingChar(string &menuTree, char opening);
};


#endif //LIST_3_STRINGVALIDATOR_H
