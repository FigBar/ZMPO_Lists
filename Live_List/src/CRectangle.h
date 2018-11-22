//
// Created by fig_bar98 on 22.11.18.
//

#ifndef LIVE_LIST_CRECTANGLE_H
#define LIVE_LIST_CRECTANGLE_H


#include <ostream>
#include "CPoint.h"

class CRectangle {
public:
    CRectangle(CPoint p1, CPoint p2);

    CRectangle(int x1, int y1, int x2, int y2);

    CRectangle operator+(CRectangle &otherRec);

    void operator=(CRectangle &otherRec);

    friend std::ostream &operator<<(std::ostream &os, const CRectangle &rectangle);

    int findMin(int a, int b);

    int findMax(int a, int b);

    const CPoint &getPoint1() const;

    void setPoint1(const CPoint &point1);

    const CPoint &getPoint2() const;

    void setPoint2(const CPoint &point2);

private:
    //void unify();

    CPoint point1;
    CPoint point2;
};


#endif //LIVE_LIST_CRECTANGLE_H
