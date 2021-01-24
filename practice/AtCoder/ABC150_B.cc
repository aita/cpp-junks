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

  ll N;
  string S;
  cin >> N >> S;

  ll ans = 0;
  string::size_type pos = S.find("ABC");
  while (pos != string::npos)
  {
    ++ans;
    pos = S.find("ABC", pos + 3);
  }
  cout << ans << endl;

  return 0;
}
