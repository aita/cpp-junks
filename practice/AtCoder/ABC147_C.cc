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

    int N;
    cin >> N;

    vector<map<int, int>> A(N);
    REP(i, N)
    {
        int a;
        cin >> a;
        REP(j, a)
        {
            int x, y;
            cin >> x >> y;
            A[i].insert({x - 1, y});
        }
    }

    int ans = 0;
    REP(i, 1 << N)
    {
        int k = 0;
        vector<int> H(N, 0);
        REP(j, N)
        {
            if (i & (1 << j))
            {
                H[j] = 1;
                ++k;
            }
        }

        bool ok = true;
        REP(j, N)
        {
            if (H[j] != 1)
                continue;

            for (auto &p : A[j])
            {
                if (H[p.first] != p.second)
                {
                    ok = false;
                }
            }
        }
        if (ok)
            ans = max(ans, k);
    }

    cout << ans << endl;

    return 0;
}
