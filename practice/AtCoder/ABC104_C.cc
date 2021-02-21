#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll D, G;
  cin >> D >> G;
  vector<ll> P(D), C(D);
  REP(i, D) {
    cin >> P[i] >> C[i];
  }

  ll ans = INF;
  REP(i, 1<<D) {
    ll sum = 0;
    ll n = 0;
    REP(j, D) {
      if (i & 1<<j) {
        sum += P[j] * (j+1) * 100 + C[j];
        n += P[j];
      }
    }
    if (sum >= G) {
      ans = min(ans, n);
    } else {
      bool found = false;
      for (ll j = D-1; j >= 0; --j) {
        if (i & 1<<j) continue;
        REP(k, P[j]) {
          sum += (j+1) * 100;
          ++n;
          if (sum >= G) {
            found = true;
            break;
          }
        }
        if (found) break;
      }
      ans = min(ans, n);
    }
  }
  cout << ans << nl;

  return 0;
}
