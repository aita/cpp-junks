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

  ll ans = 0;
  for (ll i = 1; i <= N; i += 2) {
    ll count = 0;
    ll j = 1;
    for (; j * j <= i; ++j) {
      if (i % j == 0) {
        count += 2;
      }
    }
    if (j * j == i) --count;
    if (count == 8) ++ans;
  }
  cout << ans << nl;

  return 0;
}
