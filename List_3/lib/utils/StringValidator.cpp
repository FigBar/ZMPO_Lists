//
// Created by fig_bar98 on 05.11.18.
//

#include "StringValidator.h"

void StringValidator::validateMenuCommand(string toValidate, char &errorCode, int &errorIndex, int &currentIndex,
                                          bool &correctness) {
    if (!checkSymbolInString(toValidate, 0, '[', errorCode, correctness)) {
        if (errorIndex == -1) {
            errorIndex = currentIndex;
        }
    }

    if (!checkSymbolInString(toValidate, toValidate.length() - 1, ']', errorCode, correctness)) {
        if (errorIndex == -1) {
            errorIndex = currentIndex + toValidate.length();
        }
    }
    toValidate = toValidate.substr(1, toValidate.length() - 2);
    currentIndex++;
    validateNameAndCommand(toValidate, errorCode, errorIndex, currentIndex, correctness);
    //help prompt part
    if(!checkSymbolInString(toValidate, 0, ',', errorCode, correctness)){
        if (errorIndex == -1) {
            errorIndex = currentIndex;
        }
    }
    toValidate = toValidate.substr(1, toValidate.length()-1);
    currentIndex++;

    if(!checkSymbolInString(toValidate, 0, '\'', errorCode, correctness)){
        if (errorIndex == -1) {
            errorIndex = currentIndex;
        }
    }

    if(findClosingChar(toValidate, '\'') != toValidate.length() - 1 && correctness){
        correctness = false;
        if(errorIndex == -1){
            errorIndex = currentIndex + toValidate.length() - 1;
            errorCode = '\'';
        }
    }
}

void StringValidator::validateNameAndCommand(string &toValidate, char &errorCode, int &errorIndex, int &currentIndex,
                                             bool &correctness) {
    if (!checkSymbolInString(toValidate, 0, '\'', errorCode, correctness)) {
        if (errorIndex == -1) {
            errorIndex = currentIndex;
        }
    }
    //check name part
    int nameEnd = findClosingChar(toValidate, '\'');
    if (nameEnd == -1) {
        correctness = false;
        if (errorIndex == -1) {
            errorIndex = currentIndex + nameEnd;
        }
    }
    //_________
    //coma part
    if (!checkSymbolInString(toValidate, nameEnd + 1, ',', errorCode, correctness)) {
        if (errorIndex == -1) {
            errorIndex = currentIndex + nameEnd + 1;
        }
    }
    //_____________
    //check command part
    toValidate = toValidate.substr(nameEnd + 2, toValidate.length() - (nameEnd + 2));
    currentIndex += nameEnd + 2;
    if (!checkSymbolInString(toValidate, 0, '\'', errorCode, correctness)) {
        if (errorIndex == -1) {
            errorIndex = currentIndex;
        }
    }
    int commandEnd = findClosingChar(toValidate, '\'');
    if (commandEnd == -1) {
        correctness = false;
        if (errorIndex == -1) {
            errorIndex = currentIndex;
        }
    }
    //_____________
    toValidate = toValidate.substr(commandEnd + 1, toValidate.length() - (commandEnd + 1));
    currentIndex += commandEnd + 1;
}

bool StringValidator::checkSymbolInString(string &toValidate, int index, char compareWith, char &errorCode,
                                          bool &correctness) {
    if (0 <= index && index < toValidate.length() && correctness) {
        if (toValidate[index] != compareWith) {
            correctness = false;
            if (errorCode == '~')
                errorCode = compareWith;
            return false;
        }
        return true;
    }
    return false;
}

int StringValidator::findIndexOfMissingChar(string &menuSave) {
    int index = -1;
    int openingOccurrences = 1;
    for (int i = 0; i < menuSave.size(); ++i) {
        if (menuSave[i] == '(' || menuSave[i] == '[') {
            if (menuSave[i - 1] == ',' && openingOccurrences == 1) {
                return i - 2;
            } else {
                openingOccurrences++;
            }
        }
    }
    return index;
}

int StringValidator::findClosingChar(string &menuTree, char opening) {
    char closing;
    switch (opening) {
        case '\'':
            for (int i = 0; i < menuTree.length(); ++i) {
                if (menuTree[i] == opening)
                    return i;
            }
            return -1;
        case '(':
            closing = ')';
            break;
        case '[':
            closing = ']';
            break;
        default:
            return -1;
    }
    int occurrencesBeforeClosing = 0;
    for (int j = 0; j < menuTree.length(); ++j) {
        if (menuTree[j] == opening) {
            occurrencesBeforeClosing++;
        } else if (menuTree[j] == closing) {
            occurrencesBeforeClosing--;
            if (occurrencesBeforeClosing == 0)
                return j;
        }
    }
    return -1;
}
