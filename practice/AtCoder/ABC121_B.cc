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

  ll N, M, C;
  cin >> N >> M >> C;
  vector<vector<ll>> A(N, vector<ll>(M));
  vector<ll> B(M);
  REP(i, M) {
    cin >> B[i];
  }
  REP(i, N) {
    REP(j, M) {
      cin >> A[i][j];
    }
  }

  ll ans = 0;
  REP(i, N) {
    ll x = C;
    REP(j, M) {
      x += A[i][j] * B[j];
    }
    if (x > 0) ++ans;
  }

  cout << ans << nl;

  return 0;
}
