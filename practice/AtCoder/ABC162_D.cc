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

  ll r = count(S.begin(), S.end(), 'R');
  ll g = count(S.begin(), S.end(), 'G');
  ll b = count(S.begin(), S.end(), 'B');

  ll ans = r * g * b;
  REP(i, N - 2) {
    FOR(j, i + 1, N - 1) {
        ll k = 2*j - i;
        if (k < N && S[i] != S[j] && S[k] != S[j] && S[i] != S[k]) --ans;
    }
  }
  cout << ans << nl;

  return 0;
}
