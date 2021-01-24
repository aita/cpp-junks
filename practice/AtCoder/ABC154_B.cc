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

  string s;
  cin >> s;

  auto ans = string(s.size(), 'x');
  cout << ans << nl;

  return 0;
}
