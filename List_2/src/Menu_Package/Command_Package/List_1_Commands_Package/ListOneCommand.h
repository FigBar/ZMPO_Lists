//
// Created by fig_bar98 on 22.10.18.
//

#ifndef LIST_2_LISTONECOMMAND_H
#define LIST_2_LISTONECOMMAND_H


#include "../Command.h"
#include "../../TableHandler_Package/TableHandler.h"

class ListOneCommand : public Command {
public:
    ListOneCommand(TableHandler &handler);
    virtual ~ListOneCommand();

protected:
    TableHandler *handler;
};


#endif //LIST_2_LISTONECOMMAND_H
