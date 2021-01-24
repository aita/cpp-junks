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
  cin >> N;
  vector<ll> H(N);
  REP(i, N) { cin >> H[i]; }

  vector<ll> DP(N+1);
  DP[0] = 0;
  DP[1] = abs(H[1] - H[0]);
  FOR(i, 2, N)
  {
    DP[i] = min(abs(H[i] - H[i-1]) + DP[i-1], abs(H[i] - H[i-2]) + DP[i-2]);
  }
  cout << DP[N-1] << nl;

  return 0;
}
