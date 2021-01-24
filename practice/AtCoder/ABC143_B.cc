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

  ll N;
  cin >> N;
  vector<ll> D(N);
  REP(i, N) {
    cin >> D[i];
  }

  ll ans = 0;
  REP(i, N-1) {
    FOR(j, i+1, N) {
      ans += D[i] * D[j];
    }
  }
  cout << ans << nl;

  return 0;
}
