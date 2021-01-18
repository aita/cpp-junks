#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using int64 = long long;

#define FOR(i, a, b) \
    for (int64 i = static_cast<int64>(a); i < static_cast<int64>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define DEBUG(x) cerr << __LINE__ << ": " << #x << ": " << x << '\n'

int N, M, Q;
vector<int> A(10, 0);
vector<tuple<int, int, int, int>> ABCD(50);

int ans = 0;

void dfs(int k, int a)
{
    if (k == N)
    {
        int score = 0;
        REP(i, Q)
        {
            auto abcd = ABCD[i];
            if (A[get<1>(abcd)] - A[get<0>(abcd)] == get<2>(abcd))
            {
                score += get<3>(abcd);
            }
        }
        ans = max(ans, score);
        return;
    }
    if (a > M)
        return;

    A[k] = a;
    dfs(k + 1, a);
    dfs(k + 1, a + 1);
    dfs(k, a + 1);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> Q;
    REP(i, Q)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ABCD[i] = {a - 1, b - 1, c, d};
    }

    dfs(0, 1);
    cout << ans << endl;

    return 0;
}
