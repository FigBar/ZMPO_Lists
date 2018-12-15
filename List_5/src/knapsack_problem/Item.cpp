//
// Created by fig_bar98 on 22.11.18.
//

#include "Item.h"

Item::Item(string name, double value, double weight) {
    this->name = name;
    if (value <= 0) {
        this->value = DEFAULT_ITEM_VALUE_AND_WEIGHT;
    } else {
        this->value = value;
    }
    if (weight <= 0) {
        this->weight = DEFAULT_ITEM_VALUE_AND_WEIGHT;
    } else {
        this->weight = weight;
    }
    this->partTaken = 0;
}

Item::Item(Item &copyOther) {
    this->name = copyOther.name;
    this->value = copyOther.value;
    this->weight = copyOther.weight;
    this->partTaken = 0;
}

const string &Item::getName() const {
    return name;
}

double Item::getValue() const {
    return value;
}

double Item::getWeight() const {
    return weight;
}

ostream &operator<<(ostream &os, const Item &item) {
    os << "[name: " << item.name << " value: " << item.value << " weight: " << item.weight << " partTaken: " << item.partTaken << "]" << endl;
    return os;
}

double Item::getPartTaken() const {
    return partTaken;
}

void Item::setPartTaken(double partTaken) {
    Item::partTaken = partTaken;
}

