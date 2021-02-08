#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    /*
    // ABを買わない
    ll a1 = A * X + B * Y;

    // ABだけ買う
    ll i = max(X, Y);
    ll a2 = i * (2 * C);

    // 余らないようにABを買う
    ll j = min(X, Y);
    ll a3 = j * (2 * C) + A * max(0, X - j) + B * max(0, Y - j);

    ll total = min(a1, min(a2, a3));

    cout << total << endl;
    */

    ll ans = INF;
    RANGE(i, 1, 100001) {
        ll total = i * 2 * C + max(0LL, X - i) * A + max(0LL, Y - i) * B;
        ans = min(ans, total);
    }
    cout << ans << nl;

    return 0;
}
