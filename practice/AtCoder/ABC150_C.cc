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

  vector<ll> P(N), Q(N);
  REP(i, N) cin >> P[i];
  REP(i, N) cin >> Q[i];

  vector<ll> X(N);
  iota(X.begin(), X.end(), 1);

  ll count = 0;
  ll a, b;
  do {
    if (equal(X.begin(), X.end(), P.begin()))
      a = count;
    if (equal(X.begin(), X.end(), Q.begin()))
      b = count;
    ++count;
  } while (next_permutation(X.begin(), X.end()));

  cout << abs(a - b) << endl;

  return 0;
}
