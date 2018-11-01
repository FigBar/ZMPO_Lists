//
// Created by fig_bar98 on 31.10.18.
//

#ifndef LIST_3_MENUSERIALIZER_H
#define LIST_3_MENUSERIALIZER_H

#define OP_PARENTHESIS "("
#define APOSTROPHE "'"
#define COMA ","
#define SEMICOLON ";"
#define CL_PARENTHESIS ")"
#define OP_SQ_BRACKET "["
#define CL_SQ_BRACKET "]"
#define READING_FAILED_PROMPT "The file you tried to read does not exist or it has a invalid format!!!"

#include <string>
#include "../user_interface/Menu.h"
#include "../user_interface/MenuCommand.h"

using namespace std;

class MenuSerializer {
public:
    static string serialize(Menu *startPoint);

    static bool serializeToFile(Menu *startPoint, string &fileName);

    static bool deserialize(Menu *toChange, string &menuTree, MenuAnalyzer &analyzer, string fileName);

    static bool deserializeFromFile(Menu *toChange, string &fileName, MenuAnalyzer &analyzer);

    static bool validate(string menuTree, string fileName);

private:
    static string transformMenuToString(Menu *toTransform);

    static Menu *createMenuFromString(string menuTree, MenuAnalyzer &analyzer);

    static string transformMenuCommandToString(MenuCommand *toTransform);

    static MenuCommand *createMenuCommandFromString(string menuCommandTree);

    static bool writeToFile(string &menuTree, string &fileName);

    static string readFromFile(string &fileName);

    static void readNameAndCommand(string &name, string &command, string &menuTree);

    static int findClosingChar(string &menuTree, char opening);

    static bool areParenthesisBalanced(string toValidate, string fileName);
};


#endif //LIST_3_MENUSERIALIZER_H
