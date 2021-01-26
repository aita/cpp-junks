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
  vector<ll> w(N+1), v(N+1);
  REP(i, N) {
    cin >> w[i+1] >> v[i+1];
  }

  vector<vector<ll>> dp(N+1, vector<ll>(100001, 1LL<<60LL));
  dp[0][0] = 0;
  RANGE(i, 1, N+1) {
    RANGE(j, 0, 100001) {
      if (j - v[i] >= 0) {
        dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  ll ans = 100000;
  while (dp[N][ans] > W) {
    --ans;
  }
  cout << ans << nl;

  return 0;
}
