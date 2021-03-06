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
  string::size_type pos = 0;
  while (true) {
    pos = S.find("ABC", pos);
    if (pos == string::npos) break;
    ++ans;
    pos += 3;
  }
  cout << ans << nl;

  return 0;
}
