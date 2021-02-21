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

  ll A, B, K;
  cin >> A >> B >> K;

  vector<ll> X;
  RANGE(i, 1, min(A, B) + 1) {
    if (A % i == 0 && B % i == 0) {
      X.push_back(i);
    }
  }
  ll ans = X[X.size() - K];
  cout << ans << nl;

  return 0;
}
