#include <math.h>

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double _x, double _y) {
    x = _x;
    y = _y;
}

Point::Point(const Point& a) {
    x = a.x;
    y = a.y;
}

double khoang_cach(const Point& p1, const Point& p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

Triangle::Triangle(const Point& a, const Point& b,  const Point &c) {
    p1 = a;
    p2 = b;
    p3 = c;
}

double Triangle::getPerimeter() const {
    double ab = khoang_cach(p1, p2);
    double bc = khoang_cach(p2, p3);
    double ac = khoang_cach(p1, p3);
    return ab+bc+ac;
}

double Triangle::getArea() const {
    return 0.5 * abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y));
}