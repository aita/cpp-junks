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

bool operator<(const Edge &lhs, const Edge &rhs)
{
    return lhs.weight > rhs.weight;
}

using Graph = vector<vector<Edge>>;

void Dijkstra(vector<Vertex> &vertices, const Graph &graph, VertexIndex start)
{
    priority_queue<Edge> Q;
    vector<bool> visited(vertices.size(), false);

    Q.push({-1, start, 0});
    vertices[start].d = 0;
    while (!Q.empty())
    {
        auto v = Q.top().to;
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
                Q.push(e);
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