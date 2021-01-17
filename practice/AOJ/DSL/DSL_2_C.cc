#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>


struct Point {
    int id;
    int x;
    int y;

    Point(int id, int x, int y) : id(id), x(x), y(y) {}
};

using PointList = std::vector<Point>;


class KdTree {
    struct Node {
        using Ptr = std::unique_ptr<Node>;

        Point location;
        Ptr left;
        Ptr right;

        Node(const Point& loc, Ptr l, Ptr r)
            : location(loc), left(std::move(l)), right(std::move(r)) {}

        Node(const Point& loc) : Node(loc, nullptr, nullptr) {}
    };

    Node::Ptr build(PointList::iterator first, PointList::iterator last, int depth) {
        auto k = std::distance(first, last);
        if (k < 1)
            return nullptr;

        if (k == 1) {
            return std::make_unique<Node>(*first);
        }

        if (depth % 2 == 0) {
            // horizontal
            std::sort(first, last, [](const Point& p1, const Point& p2) { return p1.x < p2.x; });
        } else {
            // vertical
            std::sort(first, last, [](const Point& p1, const Point& p2) { return p1.y < p2.y; });
        }
        auto mid = first + std::distance(first, last) / 2;
        return std::make_unique<Node>(
            *mid,
            build(first, mid, depth+1),
            build(mid+1, last, depth+1)
        );;
    }

public:
    explicit KdTree(PointList points) : _root(nullptr) {
        _root = build(points.begin(), points.end(), 0);
    }

    PointList find(int sx, int sy, int tx, int ty) {
        PointList points;
        find(*_root, sx, sy, tx, ty, 0, points);
        return points;
    }

    void find(const Node& node, int sx, int sy, int tx, int ty, int depth, PointList& ans) {
        auto p = node.location;
        if (sx <= p.x && p.x <= tx && sy <= p.y && p.y <= ty) {
            ans.push_back(p);
        }

        if (depth % 2 == 0) {
            // horizontal
            if (node.left != nullptr && sx <= p.x) {
                find(*node.left, sx, sy, tx, ty, depth+1, ans);
            }
            if (node.right != nullptr && p.x <= tx) {
                find(*node.right, sx, sy, tx, ty, depth+1, ans);
            }
        } else {
            // vertical
            if (node.left != nullptr && sy <= p.y) {
                find(*node.left, sx, sy, tx, ty, depth+1, ans);
            }
            if (node.right != nullptr && p.y <= ty) {
                find(*node.right, sx, sy, tx, ty, depth+1, ans);
            }
        }
    }

private:
    Node::Ptr _root;
};


int main() {
    using namespace std;
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    PointList points;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(i, x, y);
    }
    KdTree kdtree(points);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int sx, sy, tx, ty;
        cin >> sx >> tx >> sy >> ty;
        auto found = kdtree.find(sx, sy, tx, ty);
        std::sort(found.begin(), found.end(), [](const Point& p1, const Point& p2) { return p1.id < p2.id; });
        for (auto& p : found) {
            cout << p.id << "\n";
        }
        cout << "\n";
    }

    return 0;
}