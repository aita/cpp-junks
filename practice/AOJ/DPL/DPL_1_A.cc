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

  ll n, m;
  cin >> n >> m;
  vector<ll> C(m);
  REP(i, m) {
    cin >> C[i];
  }
  vector<ll> T(n+1, INF);
  T[0] = 0;
  REP(i, m+1) {
    RANGE(j, C[i], n+1) {
      T[j] = min(T[j], T[j-C[i]]+1);
    }
  }
  cout << T.back() << nl;

  return 0;
}
