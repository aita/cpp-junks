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

    vector<int> X(N);
    REP(i, N)
    {
        cin >> X[i];
    }

    int ans = INT_MAX;
    FOR(p, 1, 101)
    {
        int total = 0;
        REP(i, N)
        {
            total += pow(X[i] - p, 2);
        }
        ans = min(ans, total);
    }

    cout << ans << endl;

    return 0;
}
