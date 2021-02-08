#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                         \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> A(N, vector<ll>(M, 0));
  REP(i, N) {
    REP(j, M) { cin >> A[i][j]; }
  }

  ll ans = 0;
  REP(i, M - 1) {
    RANGE(j, i + 1, M) {
      ll total = 0;
      REP(k, N) {
        total += max(A[k][i], A[k][j]);
      }
      ans = max(ans, total);
    }
  }
  cout << ans << nl;

  return 0;
}
