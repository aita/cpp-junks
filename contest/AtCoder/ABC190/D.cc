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

  ll M = N;
  while (M % 2 == 0) M /= 2;

  ll ans = 0;
  for (ll i = 1; i * i <= M; ++i) {
    if (M % i == 0) {
      ++ans;
      if (i * i != M) {
        ++ans;
      }
    }
  }
  ans *= 2;

  cout << ans << nl;

  return 0;
}
