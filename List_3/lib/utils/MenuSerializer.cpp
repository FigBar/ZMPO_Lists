//
// Created by fig_bar98 on 31.10.18.
//

#include "MenuSerializer.h"
#include "../user_interface/MenuCommand.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

string MenuSerializer::serialize(Menu *startPoint) {
    return transformMenuToString(startPoint);
}

bool MenuSerializer::serializeToFile(Menu *startPoint, string &fileName) {
    string menuTree = serialize(startPoint);
    return writeToFile(menuTree, fileName);
}

bool MenuSerializer::deserialize(Menu *toChange, string &menuTree, MenuAnalyzer &analyzer, string fileName) {
    if (validate(menuTree, fileName)) {
        delete toChange;
        *toChange = *createMenuFromString(menuTree, analyzer);
        return true;
    } else {
        cout << READING_FAILED_PROMPT << endl;
        return false;
    }
}

bool MenuSerializer::deserializeFromFile(Menu *toChange, string &fileName, MenuAnalyzer &analyzer) {
    string menuTree = readFromFile(fileName);
    return deserialize(toChange, menuTree, analyzer, fileName);
}

bool MenuSerializer::validate(string menuTree, string fileName) {
    return (areParenthesisBalanced(menuTree, fileName) && !menuTree.empty());
    //TODO still need to implement a validation algorithm
}

bool MenuSerializer::writeToFile(string &menuTree, string &fileName) {
    ofstream toFileStream(fileName);
    if (toFileStream.is_open()) {
        toFileStream << menuTree << endl;
        toFileStream.close();
        return true;
    } else {
        toFileStream.close();
        return false;
    }
}

string MenuSerializer::readFromFile(string &fileName) {
    ifstream fromFileStream(fileName);
    string menuTree;
    if (fromFileStream.is_open()) {
        getline(fromFileStream, menuTree);
    }
    fromFileStream.close();
    return menuTree;
}

string MenuSerializer::transformMenuToString(Menu *toTransform) {
    stringstream stringRepresentation;
    stringRepresentation << OP_PARENTHESIS << APOSTROPHE << toTransform->getName() << APOSTROPHE
                         << COMA << APOSTROPHE << toTransform->getCommand() << APOSTROPHE << SEMICOLON;
    for (int i = 0; i < toTransform->getVector().size(); ++i) {
        if (MenuCommand *menuCommand = dynamic_cast<MenuCommand *>(toTransform->getVector()[i]))
            stringRepresentation << transformMenuCommandToString(menuCommand);
        else
            stringRepresentation << transformMenuToString(dynamic_cast<Menu *>(toTransform->getVector()[i]));
        if (i != toTransform->getVector().size() - 1)
            stringRepresentation << COMA;
    }
    stringRepresentation << CL_PARENTHESIS;
    return stringRepresentation.str();
}

string MenuSerializer::transformMenuCommandToString(MenuCommand *toTransform) {
    stringstream stringRepresentation;
    stringRepresentation << OP_SQ_BRACKET << APOSTROPHE << toTransform->getName() << APOSTROPHE << COMA
                         << APOSTROPHE << toTransform->getCommand() << APOSTROPHE << COMA
                         << APOSTROPHE << toTransform->getHelp() << APOSTROPHE << CL_SQ_BRACKET;
    return stringRepresentation.str();
}

Menu *MenuSerializer::createMenuFromString(string menuTree, MenuAnalyzer &analyzer) {
    string name;
    string command;
    readNameAndCommand(name, command, menuTree);
    Menu *menu = new Menu(name, command, analyzer);

    while (!menuTree.empty()) {
        int subMenuEnd = findClosingChar(menuTree, menuTree[0]);
        string subMenu = menuTree.substr(0, subMenuEnd + 1);
        if (subMenuEnd + 2 < menuTree.length() - 1) {
            menuTree = menuTree.substr(subMenuEnd + 2, menuTree.length() - (subMenuEnd + 2));
        } else {
            menuTree = "";
        }

        if (subMenu[0] == '(') {
            menu->addMenuItem(createMenuFromString(subMenu, analyzer));
        } else {
            menu->addMenuItem(createMenuCommandFromString(subMenu));
        }
    }
    return menu;
}

MenuCommand *MenuSerializer::createMenuCommandFromString(string menuCommandTree) {
    MenuCommand *menuCommand;
    string name;
    string command;
    readNameAndCommand(name, command, menuCommandTree);
    string help = menuCommandTree.substr(1, menuCommandTree.length() - 2);
    menuCommand = new MenuCommand(name, command, new Command(), help);
    return menuCommand;
}

void MenuSerializer::readNameAndCommand(string &name, string &command, string &menuTree) {
    menuTree = menuTree.substr(2, menuTree.length() - 3);
    int nameEnd = findClosingChar(menuTree, '\'');
    name = menuTree.substr(0, nameEnd) + "_loaded";
    menuTree = menuTree.substr(nameEnd + 3, menuTree.length() - (nameEnd + 3));
    int commandEnd = findClosingChar(menuTree, '\'');
    command = menuTree.substr(0, commandEnd);
    menuTree = menuTree.substr(commandEnd + 2, menuTree.length() - (commandEnd + 2));
}

int MenuSerializer::findClosingChar(string &menuTree, char opening) {
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

bool MenuSerializer::areParenthesisBalanced(string toValidate, string fileName) {
    stack<char> openingStack;
    char x;
    for (int i = 0; i < toValidate.length(); ++i) {
        if (toValidate[i] == '(' || toValidate[i] == '[')
            openingStack.push(toValidate[i]);

        switch (toValidate[i]) {
            case ')':
                x = openingStack.top();
                openingStack.pop();
                if (x != '(') {
                    cout << "There is no matching opening parenthesis for ')' on position " << i << " in file: "
                         << fileName << endl;
                    return false;
                }
                break;
            case ']':
                x = openingStack.top();
                openingStack.pop();
                if (x != '[') {
                    cout << "There is no matching opening parenthesis for ']' on position " << i << " in file: "
                         << fileName << endl;
                    return false;
                }
                break;
            default:
                break;
        }
    }
    if (openingStack.empty())
        return true;
    else {
        cout << "There is a missing closing parenthesis for " << openingStack.top() << " at the end of file: "
             << fileName << endl;
        return false;
    }
}

