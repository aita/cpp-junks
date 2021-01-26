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

  ll N, A, B;
  string S;
  cin >> N >> A >> B >> S;

  ll winner = 0;
  ll foreign_winner = 0;
  REP(i, N) {
    string ans = "No";
    if (S[i] == 'a') {
      if (winner < A + B) {
        ans = "Yes";
        ++winner;
      }
    } else if (S[i] == 'b') {
      if (winner < A + B && foreign_winner < B) {
        ans = "Yes";
        ++winner;
        ++foreign_winner;
      }
    }
    cout << ans << nl;
  }

  return 0;
}
