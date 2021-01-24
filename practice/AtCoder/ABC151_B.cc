#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;

#define FOR(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

constexpr auto nl = "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N, K, M;
  cin >> N >> K >> M;
  vector<ll> A(N-1);
  REP(i, N-1)
  {
    cin >> A[i];
  }
  auto total = accumulate(A.begin(), A.end(), 0);
  auto ans = max(0LL, M*N - total);
  if (ans > K) ans = -1;

  cout << ans << nl;

  return 0;
}
