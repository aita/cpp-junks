#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double pi = 3.141592653589793;

struct point {
    double x;
    double y;

    point(double x, double y)
        : x(x), y(y) {}
};

point divide(double t, const point& p1, const point& p2) {
    auto x = (1 - t) * p1.x + t * p2.x;
    auto y = (1 - t) * p1.y + t * p2.y;
    return point(x, y);
}

using point_list = vector<point>;

point_list koch_curve(int n) {
    point_list points = {point(0, 0), point(100, 0)};
    for (int i = 0; i < n; ++i) {
        point_list tmp = {points[0]};
        for (auto it = points.begin(); it != points.end()-1; ++it) {
            auto p1 = *it;
            auto p2 = *(it + 1);

            auto s = divide(1/3., p1, p2);
            auto t = divide(2/3., p1, p2);

            auto dx = t.x - s.x;
            auto dy = t.y - s.y;
            auto ux = dx * cos(pi/3) - dy * sin(pi/3) + s.x;
            auto uy = dx * sin(pi/3) + dy * cos(pi/3) + s.y;
            auto u = point(ux, uy);

            tmp.push_back(s);
            tmp.push_back(u);
            tmp.push_back(t);
            tmp.push_back(p2);
        }
        points = tmp;
    }
    return points;
}

int main() {
    int n;
    cin >> n;

    auto points = koch_curve(n);
    for (auto it = points.begin(); it != points.end(); ++it) {
        cout << it->x << " " << it->y << endl;
    }

    return 0;
}