//
// Created by fig_bar98 on 22.11.18.
//

#ifndef LIST_4_ITEM_H
#define LIST_4_ITEM_H

#include <string>
using namespace std;

class Item {
public:
    Item(string name, double value, double weight);

    const string &getName() const;

    double getValue() const;

    double getWeight() const;

private:
    string name;
    double value;
    double weight;

};


#endif //LIST_4_ITEM_H