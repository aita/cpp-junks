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

  ll N, W;
  cin >> N >> W;
  vector<ll> v(N), w(N);
  REP(i, N) {
    cin >> v[i] >> w[i];
  }

  const ll MAX_V = 10000;
  vector<vector<ll>> dp(N+1, vector<ll>(MAX_V+1, 1LL<<60LL));
  dp[0][0] = 0;
  RANGE(i, 1, N+1) {
    REP(j, MAX_V+1) {
      if (j >= v[i-1]) {
        dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i-1]] + w[i-1]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  ll ans = MAX_V;
  for (ll i = MAX_V; i >= 0; --i)
    if (dp[N][i] <= W) {
      ans = i;
      break;
    }
  cout << ans << nl;

  return 0;
}
