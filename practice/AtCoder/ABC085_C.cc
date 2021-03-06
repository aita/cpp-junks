#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;

#define FOR(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

constexpr auto nl = "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, Y;
  cin >> N >> Y;

  ll x = -1, y = -1, z = -1;
  REP(i, N + 1) {
    REP(j, N + 1 - i) {
      ll k = N - i - j;
      if (i * 10000 + j * 5000 + k * 1000 == Y) {
        x = i;
        y = j;
        z = k;
        break;
      }
    }
  }
  printf("%d %d %d\n", x, y, z);

  return 0;
}
