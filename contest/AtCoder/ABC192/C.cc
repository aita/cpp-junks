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

  ll N, K;
  cin >> N >> K;

  ll a = N;
  REP(i, K) {
    if (a == 0) break;
    auto s = to_string(a);
    sort(s.rbegin(), s.rend());
    ll g1 = atoll(s.c_str());
    sort(s.begin(), s.end());
    ll g2 = atoll(s.c_str());
    a = g1 - g2;
  }
  cout << a << nl;

  return 0;
}
