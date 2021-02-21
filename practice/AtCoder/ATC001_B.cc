#include <bits/stdc++.h>
#include <numeric>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, Q;
  cin >> N >> Q;

  dsu D(N);
  REP(i, Q) {
    ll p, a, b;
    cin >> p >> a >> b;
    if (p == 0) {
      D.merge(a, b);
    } else {
      string ans = "No";
      if (D.same(a, b))
        ans = "Yes";
        cout << ans << nl;
    }
  }

  return 0;
}
