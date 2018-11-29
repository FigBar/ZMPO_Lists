//
// Created by fig_bar98 on 22.11.18.
//

#include "Item.h"

Item::Item(string name, double value, double weight) {
    this->name = name;
    this->value = value;
    this->weight = weight;
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
    os << "[name: " << item.name << " value: " << item.value << " weight: " << item.weight << "]" << endl;
    return os;
}

