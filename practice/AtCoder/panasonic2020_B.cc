#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                         \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll H, W;
  cin >> H >> W;

  ll ans;
  if (H == 1 || W == 1) {
    ans = 1;
  } else {
    ans = (H * W + 1) / 2;
  }
  cout << ans << nl;

  return 0;
}
