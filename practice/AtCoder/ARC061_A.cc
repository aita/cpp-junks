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

  string S;
  cin >> S;

  ll ans = 0;
  ll n = S.size() - 1;
  REP(i, 1<<n) {
    ll k = 0;
    ll sum = 0;
    ll a = S[k++] - '0';
    REP(j, n) {
      ll d = S[k++] - '0';
      if (i & 1<<j) {
        a = a * 10 + d;
      } else {
        sum += a;
        a = d;
      }
    }
    sum += a;
    ans += sum;
  }
  cout << ans << nl;

  return 0;
}
