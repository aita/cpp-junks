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

  ll N;
  cin >> N;
  vector<ll> T(N);
  REP(i, N) {
    cin >> T[i];
  }

  ll ans = INF;
  REP(i, 1<<N) {
    ll t1 = 0, t2 = 0;
    REP(j, N) {
      if (i & 1<<j) {
        t1 += T[j];
      } else {
        t2 += T[j];
      }
    }
    ans = min(ans, max(t1, t2));
  }
  cout << ans << nl;

  return 0;
}
