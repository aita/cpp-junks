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

  vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));
  RANGE(i, 1, N+1) {
    RANGE(j, 1, W+1) {
      dp[i][j] = dp[i-1][j];
      if (w[i] <= j) {
        dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]);
      }
    }
  }
  cout << dp[N][W] << nl;

  return 0;
}
