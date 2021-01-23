#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using int64 = long long;

#define FOR(i, a, b) \
    for (int64 i = static_cast<int64>(a); i < static_cast<int64>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

using VertexIndex = int;

constexpr int INF_DIST = numeric_limits<int>::max();

struct Vertex
{
    int d = INF_DIST;
    VertexIndex predecessor = -1;
};

struct Edge
{
    VertexIndex from;
    VertexIndex to;
    int weight;
};

using Graph = vector<vector<Edge>>;

vector<Edge> Prim(const Graph &graph, VertexIndex start)
{
    vector<bool> visited(graph.size(), false);
    auto comp = [](Edge &u, Edge &v) { return u.weight > v.weight; };
    priority_queue<Edge, vector<Edge>, decltype(comp)> Q(comp);
    vector<Edge> edges;

    Q.push({-1, start, 0});
    vector<int> costs(graph.size(), INF_DIST);
    costs[start] = 0;
    while (!Q.empty())
    {
        auto v = Q.top();
        Q.pop();
        if (visited[v.to])
            continue;
        visited[v.to] = true;
        edges.push_back(v);
        for (auto &u : graph[v.to])
        {
            if (!visited[u.to] && u.weight < costs[u.to])
            {
                costs[u.to] = u.weight;
                Q.push(u);
            }
        }
    }
    return edges;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

    Graph G(V);
    for (int i = 0; i < E; ++i)
    {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back({s, t, w});
        G[t].push_back({t, s, w});
    }
    auto edges = Prim(G, 0);
    int total = accumulate(edges.begin(), edges.end(), 0, [](int a, Edge &v) { return a + v.weight; });
    cout << total << endl;

    return 0;
}