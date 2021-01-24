#include <bits/stdc++.h>

#include <numeric>

using namespace std;

using ll = long long;

#define FOR(i, a, b) \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

constexpr auto nl = "\n";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N;
  cin >> N;

  set<ll> A;
  REP(i, 10) {
    REP(j, 10) { A.insert(i * j); }
  }

  if (A.find(N) != A.end()) {
    cout << "Yes" << nl;
  } else {
    cout << "No" << nl;
  }

  return 0;
}
