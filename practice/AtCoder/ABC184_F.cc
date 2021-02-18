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

  ll N, T;
  cin >> N >> T;
  vector<ll> A(N);
  REP(i, N) {
    cin >> A[i];
  }

  vector<ll> L, R;
  ll a = N / 2;
  ll b = N - a;
  REP(i, 1 << a) {
    ll x = 0;
    REP(j, a) {
      if (i & 1 << j) {
        x += A[j];
      }
    }
    L.push_back(x);
  }
  REP(i, 1 << b) {
    ll x = 0;
    REP(j, b) {
      if (i & 1 << j) {
        x += A[j + a];
      }
    }
    R.push_back(x);
  }
  sort(R.begin(), R.end());

  ll ans = 0;
  REP(i, L.size()) {
    ll x = L[i];
    if (x > T)
      continue;
    ll rem = T - x;
    auto it = upper_bound(R.begin(), R.end(), rem);
    ans = max(ans, x + *(it-1));
  }
  cout << ans << nl;

  return 0;
}
