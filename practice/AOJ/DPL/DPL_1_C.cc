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

  ll N, W;
  cin >> N >> W;
  vector<ll> v(N + 1), w(N + 1);
  REP(i, N) { cin >> v[i + 1] >> w[i + 1]; }

  vector<vector<ll>> C(N + 1, vector<ll>(W + 1, 0));
  RANGE(i, 1, N + 1) {
    RANGE(j, 1, W + 1) {
      if (w[i] <= j) {
        C[i][j] = max({
          C[i - 1][j - w[i]] + v[i],
          C[i][j - w[i]] + v[i],
          C[i - 1][j],
        });
      } else {
        C[i][j] = C[i - 1][j];
      }
    }
  }
  cout << C[N][W] << nl;

  return 0;
}
