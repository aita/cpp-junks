#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define FOR(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

constexpr auto nl = "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N) { cin >> A[i]; }

  const ll MAX = 100000000;
  bitset<MAX+1> sieve;
  sieve.flip();
  sieve[0] = false;
  sieve[1] = false;
  FOR(i, 2, sqrt(MAX)+1) {
    for (ll j = 2; i*j <= MAX; ++j) {
      sieve[i*j] = false;
    }
  }
  ll ans = 0;
  REP(i, N) {
    if (sieve[A[i]]) ++ans;
  }
  cout << ans << nl;

  return 0;
}
