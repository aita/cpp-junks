#include <iostream>
#include <iomanip>
#include <array>
#include <vector>
#include <cmath>

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

bool is_orthogonal(const Vector& a, const Vector& b) {
    return equals(dot(a, b), 0.0);
}

bool is_orthogonal(const Segment& s1, const Segment& s2) {
    return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

bool is_parallel(const Vector& a, const Vector& b) {
    return equals(cross(a, b), 0.0);
}

bool is_parallel(const Segment& s1, const Segment& s2) {
    return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

enum {
    COUNTER_CLOCKWISE = 1,
    CLOCKWISE = -1,
    ONLINE_BACK = 2,
    ONLINE_FRONT = -2,
    ON_SEGMENT = 0,
};

int ccw(const Point& p0, const Point& p1, const Point& p2) {
    auto a = p1 - p0;
    auto b = p2 - p0;
    if (cross(a, b) > EPSILON) return COUNTER_CLOCKWISE;
    if (cross(a, b) < -EPSILON) return CLOCKWISE;
    if (dot(a, b) < -EPSILON) return ONLINE_BACK;
    if (norm(a) < norm(b)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
            ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(const Segment& s1, const Segment& s2) {
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double distance(const Point& a, const Point& b) {
    return abs(a - b);
}

double distanceLP(const Line& l, const Point& p) {
    return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double distanceSP(const Segment& s, const Point& p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
    return distanceLP(s, p);
}

double distance(const Segment& s1, const Segment& s2) {
    using std::min;
    if (intersect(s1, s2)) return 0.0;
    return min(min(distanceSP(s1, s2.p1), distanceSP(s1, s2.p2)),
               min(distanceSP(s2, s1.p1), distanceSP(s2, s1.p2)));
}


int main() {
    using namespace std;

    array<Point, 3> points;
    for (int i = 0; i < 2; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> points[2].x >> points[2].y;
        switch (ccw(points[0], points[1], points[2])) {
        case COUNTER_CLOCKWISE:
            cout << "COUNTER_CLOCKWISE";
            break;
        case CLOCKWISE:
            cout << "CLOCKWISE";
            break;
        case ONLINE_BACK:
            cout << "ONLINE_BACK";
            break;
        case ONLINE_FRONT:
            cout << "ONLINE_FRONT";
            break;
        case ON_SEGMENT:
            cout << "ON_SEGMENT";
            break;
        }
        cout << endl;
    }

    return 0;
}