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
  string S;
  cin >> N >> S;

  ll ans = 0;
  REP(i, 1000) {
    ll a[3] = {i / 100, (i / 10) % 10, i % 10};
    ll k = 0;
    REP(j, N) {
      ll x = S[j] - '0';
      if (x == a[k]) {
          ++k;
      }
    }
    if (k == 3) ++ans;
  }
  cout << ans << nl;

  return 0;
}
