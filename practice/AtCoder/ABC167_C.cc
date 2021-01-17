#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using int64 = long long;

#define FOR(i, a, b) \
    for (int64 i = static_cast<int64>(a); i < static_cast<int64>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define DEBUG(x) cerr << __LINE__ << ": " << #x << ": " << x << '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    vector<int> C(N);
    vector<vector<int>> A(M);

    REP(i, N)
    {
        cin >> C[i];
        A[i].resize(M);
        REP(j, M)
        {
            cin >> A[i][j];
        }
    }

    int ans = INT_MAX;
    REP(mask, 1 << N)
    {
        vector<int> U(M, 0);

        int total = 0;
        REP(i, N)
        {
            if (mask & (1 << i))
            {
                total += C[i];
                REP(j, M)
                {
                    U[j] += A[i][j];
                }
            }
        }

        if (all_of(U.begin(), U.end(), [&](int a) -> bool { return a >= X; }))
        {
            ans = min(ans, total);
        }
    }
    if (ans == INT_MAX)
        ans = -1;

    cout << ans << endl;

    return 0;
}
