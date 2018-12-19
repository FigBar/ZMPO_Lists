//
// Created by fig_bar98 on 15.12.18.
//

#include <iostream>
#include "AddItemCommand.h"
#include "../../lib/user_interface/utils/Utils.h"

AddItemCommand::AddItemCommand(KnapsackHandler *handler1) {
    this->handler = handler1;
}

void AddItemCommand::runCommand() {
    this->handler->getItems()->push_back(createItem());
}

Item *AddItemCommand::createItem() {
    cout << NAME_OF_ITEM << endl;
    string name = Utils::provideString();
    cout << VALUE_OF_ITEM << endl;
    double value = Utils::provideNumber<double>(0, 1000);
    cout << WEIGHT_OF_ITEM << endl;
    double weight = Utils::provideNumber<double>(1, 1000);
    return new Item(name, value, weight);
}
