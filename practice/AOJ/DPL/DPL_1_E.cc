#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

int levenshtein_distance(const string& s1, const string& s2) {
    auto m = s1.size();
    auto n = s2.size();
    vector<vector<ll>> dp(m+1, vector<ll>(n+1, 0));
    REP(i, m+1) {
      dp[i][0] = i;
    }
    REP(i, n+1) {
      dp[0][i] = i;
    }
    RANGE(i, 1, m+1) {
      RANGE(j, 1, n+1) {
        ll cost = s1[i-1] == s2[j-1] ? 0 : 1;
        dp[i][j] = min({
            dp[i-1][j] + 1,     // insert
            dp[i][j-1] + 1,     // delete
            dp[i-1][j-1] + cost // replace
        });
      }
    }
    return dp[m][n];
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s1, s2;
  cin >> s1 >> s2;

  cout << levenshtein_distance(s1, s2) << nl;

  return 0;
}