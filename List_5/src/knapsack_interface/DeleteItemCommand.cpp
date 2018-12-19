//
// Created by fig_bar98 on 15.12.18.
//

#include "DeleteItemCommand.h"
#include "../../lib/user_interface/utils/Utils.h"

DeleteItemCommand::DeleteItemCommand(KnapsackHandler *handler1) {
    this->handler = handler1;
}

void DeleteItemCommand::runCommand() {
    this->handler->deleteItem(getItemIndex());
}

int DeleteItemCommand::getItemIndex() {
    cout << DELETION_PROMPT << endl;
    return Utils::provideNumber<int>(0, handler->getItems()->size());
}
