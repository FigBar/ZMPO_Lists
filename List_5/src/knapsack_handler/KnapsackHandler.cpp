//
// Created by fig_bar98 on 15.12.18.
//

#include <iostream>
#include "KnapsackHandler.h"

KnapsackHandler::KnapsackHandler() {
    this->itemsList = new vector<Item *>();
}

KnapsackHandler::KnapsackHandler(vector<Item *> *itemsList) {
    this->itemsList = itemsList;
}

KnapsackHandler::~KnapsackHandler() {
    for (int i = 0; i < itemsList->size(); ++i) {
        delete itemsList->at(i);
    }
    delete itemsList;
}

void KnapsackHandler::addItem(Item *newItem) {
    itemsList->push_back(newItem);
}

void KnapsackHandler::deleteItem(int index) {
    if(index >= 0 && index < itemsList->size()) {
        delete itemsList->at(index);
        itemsList->erase(itemsList->begin() + index);
    }

}

void KnapsackHandler::deleteAllItems() {
    for (int i = 0; i < itemsList->size(); ++i) {
        delete itemsList->at(i);
    }
    itemsList->clear();
}

vector<Item *> *KnapsackHandler::getItems() {
    return this->itemsList;
}

void KnapsackHandler::printItems() {
    cout << "#################ITEM_LIST#################" << endl;
    for (int i = 0; i < itemsList->size(); ++i) {
        cout << i << ". " <<  *(itemsList->at(i)) << endl;
    }
    cout << "###########################################" << endl;
}
