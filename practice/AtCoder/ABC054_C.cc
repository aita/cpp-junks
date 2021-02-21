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

  vector<vector<ll>> G(N);
  REP(i, M) {
    ll a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<ll> V(N);
  iota(V.begin(), V.end(), 0);

  ll ans = 0;
  do {
    if (V[0] != 0) break;

    bool ok = true;
    REP(i, N - 1) {
      ll from = V[i];
      ll to = V[i+1];
      auto it = find(G[from].begin(), G[from].end(), to);
      if (it == G[from].end()) {
        ok = false;
        break;
      }
    }
    if (ok) ++ans;
  } while(next_permutation(V.begin(), V.end()));

  cout << ans << nl;

  return 0;
}
