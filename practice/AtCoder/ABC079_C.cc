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

  REP(i, 1<<3) {
    stringstream ss;
    ll k = 0;
    ll a = S[k++] - '0';
    ss << a;
    REP(j, 3) {
      ll d = S[k++] - '0';
      if (i & 1<<j) {
        ss << "+" << d;
        a += d;
      } else {
        ss << "-" << d;
        a -= d;
      }
    }
    if (a == 7) {
      ss << "=7";
      cout << ss.str() << nl;
      break;
    }
  }

  return 0;
}
