#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>

using namespace std;


struct edge {
    int src;
    int dst;
    int weight;

    edge(int src, int dst, int w) : src(src), dst(dst), weight(w) {}
};

bool operator < (const edge &a, const edge &b) {
  return a.weight > b.weight;
}


int main() {
    int n;
    cin >> n;

    vector<vector<edge>> G(n);
    for (int i = 0; i < n; ++i) {
        int u, k;
        cin >> u >> k;

        for (int j = 0; j < k; ++j) {
            int v, c;
            cin >> v >> c;
            G[u].emplace_back(u, v, c);
        }
    }

    // Dijkstra's algorithm (with pritority queue)
    vector<int> d(n, numeric_limits<int>::max());
    vector<bool> visited(n, false);
    priority_queue<edge> Q;

    Q.emplace(-1, 0, 0);
    d[0] = 0;
    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();
        visited[e.dst] = true;
        if (d[e.dst] < e.weight)
            continue;

        for (auto& x : G[e.dst]) {
            if (visited[x.dst])
                continue;
            int w = x.weight + d[e.dst];
            if (w < d[x.dst]) {
                d[x.dst] = w;
                Q.emplace(e.dst, x.dst, w);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << i << " " << d[i] << endl;
    }

    return 0;
}