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

  ll N, S, D;
  cin >> N >> S >> D;
  vector<ll> X(N), Y(N);
  REP(i, N) {
    cin >> X[i] >> Y[i];
  }

  string ans = "No";
  REP(i, N) {
    if (X[i] >= S)
      continue;
    if (Y[i] <= D)
      continue;
    ans = "Yes";
  }
  cout << ans << nl;

  return 0;
}
