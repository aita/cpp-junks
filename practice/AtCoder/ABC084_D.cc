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

  ll Q;
  cin >> Q;
  vector<ll> L(Q), R(Q);
  REP(i, Q) {
    cin >> L[i] >> R[i];
  }

  const auto N = 100000;
  vector<bool> sieve(N+1, true);
  sieve[0] = false;
  sieve[1] = false;
  for (ll i =  2; i < sqrt(N)+1; ++i) {
    for (ll j = 2; i*j <= N; ++j) {
      sieve[i*j] = false;
    }
  }
  vector<ll> A(N, 0);
  REP(i, N) {
    if (i % 2 == 0) continue;
    if (sieve[i] && sieve[(i+1)/2]) A[i] = 1;
  }
  vector<ll> S(N+1, 0);
  REP(i, N+1) {
    S[i+1] = S[i] + A[i];
  }

  REP(i, Q) {
    cout << S[R[i]+1] - S[L[i]] << nl;
  }

  return 0;
}
