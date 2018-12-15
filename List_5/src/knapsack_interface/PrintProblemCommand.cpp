//
// Created by fig_bar98 on 15.12.18.
//

#include "PrintProblemCommand.h"

PrintProblemCommand::PrintProblemCommand(KnapsackHandler *handler1) {
    this->handler = handler1;
}

void PrintProblemCommand::runCommand() {
    this->handler->printItems();
}
