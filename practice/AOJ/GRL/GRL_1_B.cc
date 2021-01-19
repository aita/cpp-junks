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

void BellmanFord(vector<Vertex> &vertices, const vector<Edge> &edges, VertexIndex S)
{
    vertices[S].d = 0;
    REP(i, vertices.size() - 1)
    {
        for (auto &e : edges)
        {
            auto &s = vertices[e.from];
            auto &d = vertices[e.to];
            if (s.d != INF_DIST && s.d + e.weight < d.d)
            {
                d.d = s.d + e.weight;
                d.predecessor = e.from;
            }
        }
    }
}

bool NegativeCycle(const vector<Vertex> &vertices, const vector<Edge> &edges)
{
    for (auto &e : edges)
    {
        auto &s = vertices[e.from];
        auto &d = vertices[e.to];
        if (s.d != INF_DIST && s.d + e.weight < d.d)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    const auto INF = numeric_limits<int>::max();

    int V, E, r;
    cin >> V >> E >> r;

    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i)
    {
        int s, t, d;
        cin >> s >> t >> d;

        edges[i] = {s, t, d};
    }

    vector<Vertex> vertices(V);
    BellmanFord(vertices, edges, r);
    if (NegativeCycle(vertices, edges))
    {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for (auto &v : vertices)
    {
        if (v.d == INF_DIST)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << v.d << endl;
        }
    }

    return 0;
}