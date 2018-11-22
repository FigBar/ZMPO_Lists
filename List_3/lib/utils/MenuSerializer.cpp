//
// Created by fig_bar98 on 31.10.18.
//

#include "SerializeMenu.h"
#include "../user_interface/MenuCommand.h"
#include "StringValidator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>

string SerializeMenu::serialize(Menu *startPoint) {
    return transformMenuToString(startPoint);
}

bool SerializeMenu::serializeToFile(Menu *startPoint, string &fileName) {
    string menuTree = serialize(startPoint);
    return writeToFile(menuTree, fileName);
}

bool SerializeMenu::deserialize(Menu *toChange, string &menuTree, MenuAnalyzer &analyzer, string fileName) {
    if (validate(menuTree, fileName)) {
        Menu *temp = createMenuFromString(menuTree, analyzer);
        *toChange = *temp;
        temp->menuItems.clear();
        delete temp;
        return true;
    } else {
        cout << READING_FAILED_PROMPT << endl;
        return false;
    }
}

bool SerializeMenu::deserializeFromFile(Menu *toChange, string &fileName, MenuAnalyzer &analyzer) {
    string menuTree = readFromFile(fileName);
    return deserialize(toChange, menuTree, analyzer, fileName);
}

bool SerializeMenu::validate(string menuTree, string fileName) {
    if (menuTree.empty())
        return false;

    bool correct = true;
    int errorIndex = -1;
    int currentIndex = 0;
    char errorCode = DEFAULT_ERROR_CODE;
    StringValidator::validateMenu(menuTree, errorCode, errorIndex, currentIndex, correct);
    if (!correct) {
        cout << ERROR_FOUND_PROMPT << fileName << INDEX_PROMPT << errorIndex
             << EXPECTED_CHAR_PROMPT << errorCode << endl;
    }
    return correct;
}

bool SerializeMenu::writeToFile(string &menuTree, string &fileName) {
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

string SerializeMenu::readFromFile(string &fileName) {
    ifstream fromFileStream(fileName);
    string menuTree;
    if (fromFileStream.is_open()) {
        getline(fromFileStream, menuTree);
    }
    fromFileStream.close();
    return menuTree;
}

string SerializeMenu::transformMenuToString(Menu *toTransform) {
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

string SerializeMenu::transformMenuCommandToString(MenuCommand *toTransform) {
    stringstream stringRepresentation;
    stringRepresentation << OP_SQ_BRACKET << APOSTROPHE << toTransform->getName() << APOSTROPHE << COMA
                         << APOSTROPHE << toTransform->getCommand() << APOSTROPHE << COMA
                         << APOSTROPHE << toTransform->getHelp() << APOSTROPHE << CL_SQ_BRACKET;
    return stringRepresentation.str();
}

Menu *SerializeMenu::createMenuFromString(string menuTree, MenuAnalyzer &analyzer) {
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
            menuTree = EMPTY_STRING;
        }

        if (subMenu[0] == OP_PARENTHESIS1) {
            menu->addMenuItem(createMenuFromString(subMenu, analyzer));
        } else {
            menu->addMenuItem(createMenuCommandFromString(subMenu));
        }
    }
    return menu;
}

MenuCommand *SerializeMenu::createMenuCommandFromString(string menuCommandTree) {
    MenuCommand *menuCommand;
    string name;
    string command;
    readNameAndCommand(name, command, menuCommandTree);
    string help = menuCommandTree.substr(1, menuCommandTree.length() - 2);
    menuCommand = new MenuCommand(name, command, nullptr, help);
    return menuCommand;
}

void SerializeMenu::readNameAndCommand(string &name, string &command, string &menuTree) {
    menuTree = menuTree.substr(2, menuTree.length() - 3);
    int nameEnd = findClosingChar(menuTree, '\'');
    name = menuTree.substr(0, nameEnd) + "_loaded";
    menuTree = menuTree.substr(nameEnd + 3, menuTree.length() - (nameEnd + 3));
    int commandEnd = findClosingChar(menuTree, '\'');
    command = menuTree.substr(0, commandEnd);
    menuTree = menuTree.substr(commandEnd + 2, menuTree.length() - (commandEnd + 2));
}

int SerializeMenu::findClosingChar(string &menuTree, char opening) {
    char closing;

    switch (opening) {
        case APOSTROPHE1:
            for (int i = 0; i < menuTree.length(); ++i) {
                if (menuTree[i] == opening)
                    return i;
            }
            return -1;
        case OP_PARENTHESIS1:
            closing = CLS_PARENTHESIS1;
            break;
        case OP_SQR_BRACKET1:
            closing = CLS_SQR_BRACKET1;
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


