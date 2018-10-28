//
// Created by fig_bar98 on 28.10.18.
//

#ifndef LIST_3_TABLEBOOTSTRAP_H
#define LIST_3_TABLEBOOTSTRAP_H

#include "../../domain/TableHandler.h"
#include "../../../../lib/user_interface/Menu.h"

#define MAIN_MENU "Main Menu"
#define MAIN_COMMAND "main"
#define CREATION_MENU "Create Tables"
#define CREATION_COMMAND "create"
#define CREATE_1 "Create one Table"
#define CR_1_COM "one"
#define CREATE_2 "Create multiple Tables"
#define CR_2_COM "multiple"
#define CREATE_3 "Clone a Table and append it"
#define CR_3_COM "clone"
#define CHANGE_MENU "Change Tables"
#define CHANGE_COMMAND "change"
#define CHANGE_1 "Set Name"
#define CH_1_COM "name"
#define CHANGE_2 "Set Size"
#define CH_2_COM "size"
#define CHANGE_3 "Insert numbereturn nullptr;r"
#define CH_3_COM "insert"
#define DELETE_MENU "Delete Tables"
#define DELETE_COMMAND "delete"
#define DELETE_1 "Delete one Table"
#define DE_1_COM "delete one"
#define DELETE_2 "Delete all Tables"
#define DE_2_COM "delete all"
#define PRINT_MENU "Print Tables"
#define PRINT_COMMAND "print"
#define PRINT_1 "Print one"
#define PR_1_COM "print one"
#define PRINT_2 "Print all"
#define PR_2_COM "print all"

class TableBootstrap {
public:
    static Menu *initializeTableMenu(TableHandler &handler1);
};


#endif //LIST_3_TABLEBOOTSTRAP_H
