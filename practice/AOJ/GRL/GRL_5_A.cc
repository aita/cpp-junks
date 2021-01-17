#include <vector>
#include <iostream>
#include <utility>

using namespace std;

struct edge {
    int src;
    int dst;
    int weight;
};

using graph = vector<vector<edge>>;

pair<int, int> visit(int v, int parent, const graph& G) {
    pair<int, int> r(0, v);
    for (const auto& e : G[v]) {
        if (e.dst == parent) {
            continue;
        }
        auto t = visit(e.dst, v, G);
        t.first += e.weight;
        if (r.first < t.first) {
            r = t;
        }
    }
    return r;
}

int main() {
    int n;
    cin >> n;

    graph G(n);
    for (int i = 0; i < n-1; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back(edge{s, t, w});
        G[t].push_back(edge{t, s, w});
    }
    auto r = visit(0, -1, G);
    auto t = visit(r.second, -1, G);
    cout << t.first << endl;

    return 0;
}