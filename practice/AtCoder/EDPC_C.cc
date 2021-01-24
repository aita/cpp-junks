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

  ll N;
  cin >> N;
  vector<ll> A(N), B(N), C(N);
  REP(i, N) {
    cin >> A[i] >> B[i] >> C[i];
  }
  vector<array<ll, 3>> DP(N);
  DP[0] = {A[0], B[0], C[0]};
  FOR(i, 1, N) {
    DP[i] = {
      A[i] + max(DP[i-1][1], DP[i-1][2]),
      B[i] + max(DP[i-1][0], DP[i-1][2]),
      C[i] + max(DP[i-1][0], DP[i-1][1]),
    };
  }
  auto last = DP[N-1];
  ll ans = max(last[0], max(last[1], last[2]));
  cout << ans << nl;

  return 0;
}
