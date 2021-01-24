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

  ll N, C;
  cin >> N >> C;

  vector<pair<ll, ll>> events;
  REP(i, N) {
    ll a, b, c;
    cin >> a >> b >> c;
    events.emplace_back(a-1, c);
    events.emplace_back(b, -c);
  }
  sort(events.begin(), events.end());

  ll ans = 0;
  ll fee = 0;
  ll t = 0;
  for (auto [x, y] : events) {
    if (x != t) {
      ans += min(C, fee) * (x - t);
      t = x;
    }
    fee += y;
  }
  cout << ans << nl;

  return 0;
}
