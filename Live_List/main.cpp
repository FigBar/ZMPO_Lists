#include <iostream>
#include "src/CPoint.h"
#include "src/CRectangle.h"

int main() {

    CPoint a(1, 1), b(2, 2);
    CPoint c(3, 3), d(a);

    std::cout << a << b << c << d << std::endl;

    c = b;
    c.setX(10);
    c.setY(10);
    a.setX(20);
    a.setY(20);

    std::cout << a << b << c << d << std::endl;

    a = b + c;

    std::cout << a << b << c << std::endl;

    CRectangle p1(0, 0, 4, 5);
    CRectangle p2(1, 2, 8, 3);

    std::cout << p1 + p2 << std::endl;

    return 0;

}