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
  vector<ll> L(N, INF);
  L[0] = A[0];
  ll k = 1;
  RANGE(i, 1, N) {
    if (L[k-1] < A[i]) {
      L[k] = A[i];
      ++k;
    } else {
      auto it = lower_bound(L.begin(), L.begin()+k, A[i]);
      *it = A[i];
    }
  }
  cout << k << nl;

  return 0;
}
