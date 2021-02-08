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
  vector<ll> A(M), B(M);
  REP(i, M) {
    cin >> A[i] >> B[i];
    --A[i];
    --B[i];
  }
  ll K;
  cin >> K;
  vector<ll> C(K), D(K);
  REP(i, K) {
    cin >> C[i] >> D[i];
    --C[i];
    --D[i];
  }

  ll ans = 0;
  REP(i, 1<<K) {
    vector<bool> X(M, false);
    REP(j, K) {
      if (i & 1 << j) {
        X[C[j]] = true;
      } else {
        X[D[j]] = true;
      }
    }
    ll total = 0;
    REP(i, M) {
      if (X[A[i]] && X[B[i]]) ++total;
    }
    ans = max(ans, total);
  }
  cout << ans << nl;

  return 0;
}
