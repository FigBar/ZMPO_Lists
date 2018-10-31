//
// Created by fig_bar98 on 31.10.18.
//

#include "MenuSerializer.h"
#include "../user_interface/MenuCommand.h"
#include <iostream>
#include <fstream>
#include <sstream>

string MenuSerializer::serialize(Menu *startPoint) {
    return transformMenuToString(startPoint);
}

bool MenuSerializer::serializeToFile(Menu *startPoint, string &fileName) {
    string menuTree = serialize(startPoint);
    return writeToFile(menuTree, fileName);
}

bool MenuSerializer::deserialize(Menu *toChange, string &menuTree) {
    return false;
}

bool MenuSerializer::deserializeFromFile(Menu *toChange, string &fileName) {
    return false;
}

bool MenuSerializer::validate(string menuTree) {
    return false;
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


