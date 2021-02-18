#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

ll A, B;
vector<ll> X(35);

ll solve(ll n, ll k) {
  if (n > B)
    return 1;

  bool ok = true;
  REP(i, k) {
    if (gcd(n, X[i]) != 1) {
      ok = false;
      break;
    }
  }
  ll ans = 0;
  if (ok) {
    X[k] = n;
    ans += solve(n+1, k+1);
  }
  ans += solve(n+1, k);
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> A >> B;
  cout << solve(A, 0) << nl;

  return 0;
}
