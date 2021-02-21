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

  string ans = "Yes";
  REP(i, S.size()) {
    if (i % 2 == 0) {
      // 奇数番目
      if (!islower(S[i])) {
        ans = "No";
        break;
      }
    } else {
      // 偶数番目
      if (!isupper(S[i])) {
        ans = "No";
        break;
      }
    }
  }
  cout << ans << nl;

  return 0;
}
