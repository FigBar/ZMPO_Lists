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

#include <string>
#include "../user_interface/Menu.h"
#include "../user_interface/MenuCommand.h"

using namespace std;

class MenuSerializer {
public:
    static string serialize(Menu *startPoint);

    static bool serializeToFile(Menu *startPoint, string &fileName);

    static bool deserialize(Menu *toChange, string &menuTree);

    static bool deserializeFromFile(Menu *toChange, string &fileName);

    static bool validate(string menuTree);

private:
    static string transformMenuToString(Menu *toTransform);

    static string transformMenuCommandToString(MenuCommand *toTransform);

    static bool writeToFile(string &menuTree, string &fileName);
};


#endif //LIST_3_MENUSERIALIZER_H
