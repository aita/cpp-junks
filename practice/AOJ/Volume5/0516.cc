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

  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
  }

  vector<ll> s(N+1, 0);
  REP(i, N) {
    s[i+1] = s[i] + A[i];
  }

  ll ans = -INF;
  REP(i, N-K+1) {
    ans = max(ans, s[K+i] - s[i]);
  }
  cerr << ans << nl;

  return 0;
}
