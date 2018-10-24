//
// Created by fig_bar98 on 21.10.18.
//

#ifndef LIST_2_CLONETABLE_H
#define LIST_2_CLONETABLE_H
#define CLONE_REQUEST "Please provide index of Table you want to clone"

#include "../../MenuCommand.h"
#include "ListOneCommand.h"

class CloneTable : public ListOneCommand {
public:
    CloneTable(TableHandler &handler);
    void runCommand();
    bool appendClone(int index);
};


#endif //LIST_2_CLONETABLE_H
