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
  vector<ll> A(N), B(N);
  REP(i, N) {
    cin >> A[i] >> B[i];
  }

  vector<ll> P;
  copy(A.begin(), A.end(), back_inserter(P));
  copy(B.begin(), B.end(), back_inserter(P));

  ll ans = INF;
  REP(i, P.size()) {
    REP(j, P.size()) {
      if (i == j)
        continue;
      ll total = 0;
      REP(k, N) {
        total += abs(P[i] - A[k]) + abs(A[k] - B[k]) + abs(B[k] - P[j]);
      }
      ans = min(ans, total);
    }
  }
  cout << ans << nl;

  return 0;
}
