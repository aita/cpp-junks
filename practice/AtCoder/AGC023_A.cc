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

  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
  }
  vector<ll> S(N+1);
  map<ll, ll> M;
  REP(i, N) {
    S[i+1] = S[i] + A[i];
  }
  REP(i, N+1) {
    ++M[S[i]];
  }

  ll ans = 0;
  for (auto [k, v]: M) {
    ans += v * (v - 1) / 2;
  }
  cout << ans << nl;

  return 0;
}
