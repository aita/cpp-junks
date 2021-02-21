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

  ll N, M;
  cin >> N >> M;
  vector<vector<bool>> G(N, vector<bool>(N, false));
  REP(i, M) {
    ll x, y;
    cin >> x >> y;
    --x; --y;
    G[x][y] = true;
    G[y][x] = true;
  }

  ll ans = 0;
  REP(i, 1<<N) {
    vector<ll> members;
    REP(j, N) {
      if (i & 1<<j) {
        members.push_back(j);
      }
    }

    bool ok = true;
    for (auto j : members) {
      for (auto k : members) {
        if (j == k) continue;
        if (!G[j][k]) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) {
      ans = max(ans, (ll)members.size());
    }
  }
  cout << ans << nl;

  return 0;
}
