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

  ll N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<vector<tuple<ll,ll,ll>>> G(N+1);
  REP(i, M) {
    ll a, b, t, k;
    cin >> a >> b >> t >> k;
    G[a].push_back({b, t, k});
    G[b].push_back({a, t, k});
  }

  using edge = pair<ll, ll>;
  priority_queue<edge, vector<edge>, greater<edge>> Q;
  vector<bool> visited(N+1, false);
  vector<ll> W(N+1, INF);

  ll ans = -1;
  for (auto &[b, t, k]: G[X]) {
    Q.push({t, b});
  }
  while (!Q.empty())
  {
    auto [t, p] = Q.top();
    Q.pop();
    if (visited[p]) {
        continue;
    }
    visited[p] = true;

    if (p == Y) {
      ans = t;
      break;
    }

    for (auto &[b, td, k]: G[p]) {
      ll rem = (k - (t % k)) % k;
      ll w = t + rem + td;
      if (!visited[b] && w < W[b]) {
        Q.push({w, b});
      }
    }
  }

  cout << ans << nl;

  return 0;
}
