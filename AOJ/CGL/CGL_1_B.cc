#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdio>

const double EPSILON = 1e-10;

inline bool equals(double a, double b) {
    return std::fabs(a - b) < EPSILON;
}

struct Point {
    double x;
    double y;

    bool operator < (const Point& p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point& p) const {
        return equals(x, p.x) && equals(y, p.y);
    }
};

Point operator + (const Point& p1, const Point& p2) {
    return Point{p1.x + p2.x, p1.y + p2.y};
}

Point operator - (const Point& p1, const Point& p2) {
    return Point{p1.x - p2.x, p1.y - p2.y};
}

Point operator * (const Point& p1, double k) {
    return Point{p1.x * k, p1.y * k};
}

struct Segment {
    Point p1, p2;
};

struct Circle {
    Point center;
    double radius;
};

using Vector = Point;
using Line = Segment;
using Polygon = std::vector<Point>;


double norm(const Vector& p) {
    return p.x * p.x + p.y * p.y;
}

double abs(const Vector& p) {
    return std::sqrt(norm(p));
}

double dot(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y;
}

double cross(const Vector& a, const Vector& b) {
    return a.x * b.y - a.y * b.x;
}

Vector projection(const Segment& s, const Point& p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
}

Vector reflection(const Segment& s, const Point& p) {
    return p + (projection(s, p) - p) * 2.0;
}

int main() {
    using namespace std;

    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    Segment s{p1, p2};

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        double x, y;
        cin >> x >> y;
        auto p = reflection(s, Point{x, y});
        cout << setprecision(20) << p.x << " " << p.y << endl;
    }

    return 0;
}