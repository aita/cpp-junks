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

    int N, M;
    cin >> N >> M;

    vector<vector<int>> S(M);
    vector<int> P(M);
    REP(i, M)
    {
        int k;
        cin >> k;
        S[i].resize(k);
        REP(j, k)
        {
            cin >> S[i][j];
        }
    }
    REP(i, M)
    {
        cin >> P[i];
    }

    int ans = 0;
    REP(mask, 1 << N)
    {
        bool ok = true;
        REP(i, M)
        {
            int k = 0;
            REP(j, S[i].size())
            {
                int q = S[i][j] - 1;
                if (mask & (1 << q))
                {
                    ++k;
                }
            }
            if (k % 2 != P[i])
                ok = false;
        }
        if (ok)
            ++ans;
    }

    cout << ans << endl;

    return 0;
}
