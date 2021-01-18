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

    int A, B;
    cin >> A >> B;

    int ans = 0;
    int count = 1;
    while (count < B)
    {
        count += A - 1;
        ++ans;
    }

    cout << ans << endl;

    return 0;
}
