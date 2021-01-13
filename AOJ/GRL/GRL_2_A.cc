#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <numeric>

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

    int V, E;
    cin >> V >> E;

    vector<vector<edge>> G(V);
    for (int i = 0; i < E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].emplace_back(t, w);
        G[t].emplace_back(s, w);
    }

    // Prim's algorithm
    vector<int> mincost(V, INF);
    vector<bool> visited(V, false);
    priority_queue<edge> Q;

    Q.emplace(0, 0);
    mincost[0] = 0;
    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();
        if (visited[e.v])
            continue;
        visited[e.v] = true;

        for (auto& u : G[e.v]) {
            if (!visited[u.v] && u.weight < mincost[u.v]) {
                mincost[u.v] = u.weight;
                Q.emplace(u.v, u.weight);
            }
        }
    }

    auto total = accumulate(mincost.begin(), mincost.end(), 0);
    cout << total << endl;

    return 0;
}