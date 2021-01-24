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
  string S;

  cin >> N >> S;

  auto ans = transform(S.begin(), S.end(), S.begin(), [&](char c) -> char {
    c = c + (char)N;
    if (c > 'Z')
      c = c - ('Z' - 'A' + 1);
    return c;
  });
  cout << S << nl;

  return 0;
}
