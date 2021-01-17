#include <vector>
#include <iostream>
#include <limits>
#include <queue>

using namespace std;

struct edge {
    int v;
    int weight;

    edge(int v, int w) : v(v), weight(w) {}
};

bool operator < (const edge &a, const edge &b) {
  return a.weight > b.weight;
}

int main() {
    auto const INF = numeric_limits<int>::max();

    int V, E, r;
    cin >> V >> E >> r;

    vector<vector<edge>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].emplace_back(t, d);
    }

    // Dijkstra's algorithm
    vector<int> d(V, INF);
    vector<bool> visited(V, false);
    priority_queue<edge> Q;

    Q.emplace(r, 0);
    d[r] = 0;
    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();
        if (visited[e.v])
            continue;
        visited[e.v] = true;

        for (auto& u : G[e.v]) {
            int w = u.weight + d[e.v];
            if (!visited[u.v] && w < d[u.v]) {
                d[u.v] = w;
                Q.emplace(u.v, w);
            }
        }
    }

    for (auto x : d) {
        if (x != INF) {
            cout << x << endl;
        } else {
            cout << "INF" << endl;
        }
    }

    return 0;
}