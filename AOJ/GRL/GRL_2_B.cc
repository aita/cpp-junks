#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <numeric>

using namespace std;

struct edge {
    int src;
    int dst;
    int weight;
};

using graph = vector<vector<edge>>;


void solve(const graph& G) {
    auto const INF = numeric_limits<int>::max();
    auto const V = G.size();
    // Prim's algorithm
    vector<int> mincost(V, INF);
    vector<bool> visited(V, false);
    priority_queue<edge> Q;

    Q.emplace(0, 0);
    mincost[0] = 0;
    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();
        if (visited[e.dst])
            continue;
        visited[e.dst] = true;

        for (auto& u : G[e.dst]) {
            if (!visited[u.dst] && u.weight < mincost[u.dst]) {
                mincost[u.dst] = u.weight;
                Q.emplace(u.dst, u.weight);
            }
        }
    }
}

int main() {
    int V, E, r;
    cin >> V >> E >> r;

    graph G(V);
    for (int i = 0; i < E; ++i) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back(edge{s, t, w});
    }

    auto total = accumulate(mincost.begin(), mincost.end(), 0);
    cout << total << endl;

    return 0;
}