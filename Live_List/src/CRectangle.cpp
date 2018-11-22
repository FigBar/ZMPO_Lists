//
// Created by fig_bar98 on 22.11.18.
//

#include "CRectangle.h"

CRectangle::CRectangle(CPoint p1, CPoint p2) : point1(p1), point2(p2) {
}

CRectangle::CRectangle(int x1, int y1, int x2, int y2) : point1(x1, y1), point2(x2, y2) {
}

CRectangle CRectangle::operator+(CRectangle &otherRec) {
    int leftX = findMin(
            findMin(this->point1.getX(), this->point2.getX()),
            findMin(otherRec.point1.getX(), otherRec.point2.getX()));
    int leftY = findMin(
            findMin(this->point1.getY(), this->point2.getY()),
            findMin(otherRec.point1.getY(), otherRec.point2.getY()));

    int rightX = findMax(
            findMax(this->point1.getX(), this->point2.getX()),
            findMax(otherRec.point1.getX(), otherRec.point2.getX()));

    int rightY = findMax(
            findMax(this->point1.getY(), this->point2.getY()),
            findMax(otherRec.point1.getY(), otherRec.point2.getY()));
    CRectangle toReturn(leftX, leftY, rightX, rightY);
    return toReturn;
}

void CRectangle::operator=(CRectangle &otherRec) {
    this->point1 = otherRec.point1;
    this->point2 = otherRec.point2;
}

/*void CRectangle::unify() {
    int p1x = findMin(point1.getX(), point2.getX());
    point1.setX(p1x);
    int p1y = findMin(point1.getY(), point2.getY());
    point1.setY(p1y);

    int p2x = findMax(point1.getX(), point2.getX());
    point2.setX(p2x);
    int p2y = findMax(point1.getY(), point2.getY());
    point2.setY(p2y);

}*/

int CRectangle::findMin(int a, int b) {
    if (a >= b) return b;
    else return a;

}

int CRectangle::findMax(int a, int b) {
    if (a >= b) return a;
    else return b;
}

const CPoint &CRectangle::getPoint1() const {
    return point1;
}

void CRectangle::setPoint1(const CPoint &point1) {
    CRectangle::point1 = point1;
}

const CPoint &CRectangle::getPoint2() const {
    return point2;
}

void CRectangle::setPoint2(const CPoint &point2) {
    CRectangle::point2 = point2;
}

std::ostream &operator<<(std::ostream &os, const CRectangle &rectangle) {
    os << "point1: " << rectangle.point1 << " point2: " << rectangle.point2;
    return os;
}
