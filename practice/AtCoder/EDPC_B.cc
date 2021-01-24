#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define FOR(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

constexpr auto nl = "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, K;
  cin >> N >> K;
  vector<ll> H(N);
  REP(i, N) { cin >> H[i]; }

  vector<ll> DP(N, INF);
  DP[0] = 0;
  FOR(i, 1, N)
  {
    FOR(j, 1, K+1) {
      if (i-j < 0) break;
      DP[i] = min(DP[i], DP[i-j] + abs(H[i] - H[i-j]));
    }
  }
  cout << DP[N-1] << nl;

  return 0;
}
