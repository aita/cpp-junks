#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

ll solve(string s) {
  ll total = 0;
  ll n = s.size()-1;
  REP(i, 1<<n) {
    ll sum = s[0] - '0';
    REP(j, n) {
      ll next = s[j+1] - '0';
      if (i & 1 << j) {
        total += sum;
        sum = next;
      } else {
        sum = sum * 10 + next;
      }
    }
    total += sum;
  }
  return total;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;

  cout << solve(S) << nl;

  return 0;
}
