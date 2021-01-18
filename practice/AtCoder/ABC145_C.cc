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

    vector<pair<int, int>> C(N);
    REP(i, N)
    {
        int x, y;
        cin >> x >> y;
        C[i] = {x, y};
    }

    int c = 0;
    double ans = 0;
    vector<int> P(N);
    iota(P.begin(), P.end(), 0);
    do
    {
        double distance = 0;
        auto A = C[P[0]];
        FOR(i, 1, N)
        {
            auto B = C[P[i]];
            distance += sqrt(pow(B.first - A.first, 2) + pow(B.second - A.second, 2));
            A = B;
        }
        ans += distance;
        ++c;
    } while (next_permutation(P.begin(), P.end()));
    ans /= c;

    cout << setprecision(20) << ans << endl;

    return 0;
}
