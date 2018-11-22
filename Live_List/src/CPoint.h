//
// Created by fig_bar98 on 22.11.18.
//

#ifndef LIVE_LIST_CPOINT_H
#define LIVE_LIST_CPOINT_H


#include <ostream>

class CPoint {
public:
    CPoint(int x, int y);

    CPoint(CPoint &copyOther);

    void operator=(const CPoint &copyOther);

    CPoint operator+(CPoint &toAdd);

    friend std::ostream &operator<<(std::ostream &os, const CPoint &point);

    ~CPoint();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);


private:
    int* x;
    int* y;
};


#endif //LIVE_LIST_CPOINT_H
