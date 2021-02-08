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

  ll N, Q;
  string S;
  cin >> N >> Q >> S;
  vector<ll> L(Q), R(Q);
  REP(i, Q) {
    cin >> L[i] >> R[i];
  }

  vector<ll> A(N, 0);
  REP(i, N-1) {
    if (S[i] == 'A' && S[i+1] == 'C') A[i] = 1;
  }
  vector<ll> C(N+1, 0);
  REP(i, N) {
    C[i+1] = C[i] + A[i];
  }

  REP(i, Q) {
    cout << C[R[i]-1] - C[L[i]-1] << nl;
  }

  return 0;
}
