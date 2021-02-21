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

  string S;
  cin >> S;

  ll ans = 0;
  REP(i, S.size() - 1) {
    ll len = 0;
    RANGE(j, i, S.size()) {
      bool ok = true;
      switch (S[j]) {
        case 'A':
        case 'C':
        case 'G':
        case 'T':
          break;
        default:
          ok = false;
      }
      if (!ok) break;
      ++len;
    }
    ans = max(ans, len);
  }
  cout << ans << nl;

  return 0;
}
