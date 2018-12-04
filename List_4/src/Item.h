//
// Created by fig_bar98 on 22.11.18.
//

#ifndef LIST_4_ITEM_H
#define LIST_4_ITEM_H

#define DEFAULT_ITEM_VALUE_AND_WEIGHT 1

#include <string>
#include <ostream>

using namespace std;

class Item {
public:
    Item(string name, double value, double weight);

    const string &getName() const;

    double getValue() const;

    double getWeight() const;

    friend ostream &operator<<(ostream &os, const Item &item);

private:
    string name;
    double value;
    double weight;

};


#endif //LIST_4_ITEM_H
