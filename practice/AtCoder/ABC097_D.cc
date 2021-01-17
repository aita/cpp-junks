#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using int64 = long long;

#define FOR(i, a, b) for (int64 i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define DEBUG(x) cerr << __LINE__ << ": " << #x << ": " << x << '\n'

class UnionFind
{
public:
    UnionFind(std::size_t n) : parent_(n)
    {
        std::iota(parent_.begin(), parent_.end(), 0);
    }

    // xが属する木の根を探索する
    int find(int x)
    {
        if (parent_[x] == x)
            return x;
        return parent_[x] = find(parent_[x]);
    }

    // 木の併合
    void unite(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x == root_y)
            return;
        parent_[root_x] = root_y;
    }

    // 同じ木に属するか
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

private:
    std::vector<int> parent_;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    REP(i, N)
    {
        cin >> P[i];
    }

    UnionFind tree(N);
    REP(i, M)
    {
        int x, y;
        cin >> x >> y;
        tree.unite(x - 1, y - 1);
    }

    int counter = 0;
    REP(i, N)
    {
        if (tree.same(i, P[i] - 1))
        {
            ++counter;
        }
    }
    cout << counter << endl;

    return 0;
}
