//
// Created by fig_bar98 on 22.11.18.
//

#include "CPoint.h"

CPoint::CPoint(int x, int y) {
    this->x = new int(x);
    this->y = new int(y);
}

CPoint::CPoint(CPoint &copyOther) {
    x = new int(*copyOther.x);
    y = new int(*copyOther.y);
}

void CPoint::operator=(const CPoint &copyOther) {
    *x = *(copyOther.x);
    *y = *(copyOther.y);
}

CPoint CPoint::operator+(CPoint &toAdd) {
    CPoint outcome((*(this->x) + *(toAdd.x)), (*(this->y) + *(toAdd.y)));
    return outcome;
}

std::ostream &operator<<(std::ostream &os, const CPoint &point) {
    os << "x: " << *point.x << " y: " << *point.y;
    return os;
}

CPoint::~CPoint() {
    delete x;
    delete y;
}

int CPoint::getX() const {
    return *x;
}

void CPoint::setX(int x) {
    *CPoint::x = x;
}

int CPoint::getY() const {
    return *y;
}

void CPoint::setY(int y) {
    *CPoint::y = y;
}





