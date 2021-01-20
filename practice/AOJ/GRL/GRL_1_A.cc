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
    VertexIndex from, to;
    int weight;
};

using Graph = vector<vector<Edge>>;

void Dijkstra(vector<Vertex> &vertices, const Graph &graph, VertexIndex start)
{
    using Key = pair<int, VertexIndex>;
    auto comp = [](Key &a, Key &b) -> bool { return a.first > b.first; };
    priority_queue<Key, vector<Key>, decltype(comp)> Q(comp);
    vector<bool> visited(vertices.size(), false);

    Q.emplace(0, start);
    vertices[start].d = 0;
    while (!Q.empty())
    {
        auto v = Q.top().second;
        Q.pop();
        if (visited[v])
            continue;
        visited[v] = true;
        for (auto &e : graph[v])
        {
            int w = e.weight + vertices[v].d;
            if (!visited[e.to] && w < vertices[e.to].d)
            {
                vertices[e.to].d = w;
                vertices[e.to].predecessor = v;
                Q.emplace(w, e.to);
            }
        }
    }
}

int main()
{
    int V, E, r;
    cin >> V >> E >> r;

    Graph G(V);
    for (int i = 0; i < E; ++i)
    {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].push_back({s, t, d});
    }

    vector<Vertex> vertices(V);
    Dijkstra(vertices, G, r);

    for (auto &x : vertices)
    {
        if (x.d != INF_DIST)
        {
            cout << x.d << endl;
        }
        else
        {
            cout << "INF" << endl;
        }
    }

    return 0;
}