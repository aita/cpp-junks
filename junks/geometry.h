#include <cmath>
#include <limits>
#include <vector>

constexpr double EPSILON = 1e-10;

inline bool equals(double a, double b) { return std::abs(a - b) <= EPSILON; }

struct Point
{
  double x;
  double y;

  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }

  bool operator==(const Point &p) const
  {
    return equals(x, p.x) && equals(y, p.y);
  }
};

Point operator+(const Point &p1, const Point &p2)
{
  return Point{p1.x + p2.x, p1.y + p2.y};
}

Point operator-(const Point &p1, const Point &p2)
{
  return Point{p1.x - p2.x, p1.y - p2.y};
}

Point operator*(const Point &p1, double k) { return Point{p1.x * k, p1.y * k}; }

template <typename tag>
struct PointPair
{
  Point p1, p2;
};

struct segment_tag
{
};
struct line_tag
{
};

struct Circle
{
  Point center;
  double radius;
};

using Segment = PointPair<segment_tag>;
using Line = PointPair<line_tag>;

double norm(const Point &p) { return p.x * p.x + p.y * p.y; }

double abs(const Point &p) { return std::sqrt(norm(p)); }

double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }

double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

Point projection(const Segment &s, const Point &p)
{
  Point base = s.p2 - s.p1;
  double r = dot(p - s.p1, base) / norm(base);
  return s.p1 + base * r;
}

Point reflection(const Segment &s, const Point &p)
{
  return p + (projection(s, p) - p) * 2.0;
}

bool is_orthogonal(const Point &a, const Point &b)
{
  return equals(dot(a, b), 0.0);
}

bool is_orthogonal(const Segment &s1, const Segment &s2)
{
  return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

bool is_parallel(const Point &a, const Point &b)
{
  return equals(cross(a, b), 0.0);
}

bool is_parallel(const Segment &s1, const Segment &s2)
{
  return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

enum
{
  COUNTER_CLOCKWISE = 1,
  CLOCKWISE = -1,
  ONLINE_BACK = 2,
  ONLINE_FRONT = -2,
  ON_SEGMENT = 0,
};

int ccw(const Point &p0, const Point &p1, const Point &p2)
{
  auto a = p1 - p0;
  auto b = p2 - p0;
  if (cross(a, b) > EPSILON)
    return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPSILON)
    return CLOCKWISE;
  if (dot(a, b) < -EPSILON)
    return ONLINE_BACK;
  if (norm(a) < norm(b))
    return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool intersect(const Point &p1, const Point &p2, const Point &p3,
               const Point &p4)
{
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

bool intersect(const Segment &s1, const Segment &s2)
{
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double distance(const Point &a, const Point &b) { return abs(a - b); }

double distanceLP(const Line &l, const Point &p)
{
  return std::abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

double distanceSP(const Segment &s, const Point &p)
{
  if (dot(s.p2 - s.p1, p - s.p1) < 0.0)
    return abs(p - s.p1);
  if (dot(s.p1 - s.p2, p - s.p2) < 0.0)
    return abs(p - s.p2);
  return distanceLP(s, p);
}

double distance(const Segment &s1, const Segment &s2)
{
  using std::fmin;
  if (intersect(s1, s2))
    return 0.0;
  return fmin(fmin(distanceSP(s1, s2.p1), distanceSP(s1, s2.p2)),
              fmin(distanceSP(s2, s1.p1), distanceSP(s2, s1.p2)));
}

Point cross_point(const Segment &s1, const Segment &s2)
{
  auto base = s2.p2 - s2.p1;
  auto d1 = std::abs(cross(base, s1.p1 - s2.p1));
  auto d2 = std::abs(cross(base, s1.p2 - s2.p1));
  auto t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}
