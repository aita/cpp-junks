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

class AdjacencyMatrix
{
public:
    AdjacencyMatrix(int n) : distances_(n, vector<int>(n, INF_DIST))
    {
        for (int i = 0; i < n; ++i)
            operator()(i, i) = 0;
    }

    int operator()(VertexIndex i, VertexIndex j) const
    {
        return distances_[i][j];
    }

    int &operator()(VertexIndex i, VertexIndex j)
    {
        return distances_[i][j];
    }

    int dim() const { return distances_.size(); }

private:
    vector<vector<int>> distances_;
};

void WarshallFloyd(AdjacencyMatrix &D)
{
    for (int k = 0; k < D.dim(); ++k)
    {
        for (int i = 0; i < D.dim(); ++i)
        {
            for (int j = 0; j < D.dim(); ++j)
            {
                if (D(i, k) != INF_DIST && D(k, j) != INF_DIST)
                    D(i, j) = min(D(i, j), D(i, k) + D(k, j));
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;

    AdjacencyMatrix D(V);
    for (int i = 0; i < E; ++i)
    {
        int s, t, d;
        cin >> s >> t >> d;
        D(s, t) = d;
    }

    WarshallFloyd(D);
    for (int i = 0; i < V; ++i)
    {
        if (D(i, i) < 0)
        {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            auto x = D(i, j);
            if (x != INF_DIST)
            {
                cout << x;
            }
            else
            {
                cout << "INF";
            }
            if (j == V - 1)
            {
                cout << "\n";
            }
            else
            {
                cout << " ";
            }
        }
    }

    return 0;
}