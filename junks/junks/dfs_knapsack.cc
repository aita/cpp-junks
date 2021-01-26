/* DFSによる0-1ナップサック問題の解法

問題: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_B
*/
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

ll N, W;
vector<ll> v, w;

// i番目以降の品物の重さの総和がj以下になるとき、取りうる価値の総和の最大値を返す
ll solve(ll i, ll j) {
  ll ans;
  if (i == N) {
    // 品物の残りが無いので重さは0
    ans = 0;
  } else if (j < w[i]) {
    // 品物iが入らないので、品物iを抜きで総和を計算する
    ans = solve(i+1, j);
  } else {
    // 品物iを入れたときの総和と入れないときの総和で比較
    ans = max(solve(i+1, j), solve(i+1, j-w[i]) + v[i]);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> W;
  v.reserve(N);
  w.reserve(N);
  REP(i, N) {
    cin >> v[i] >> w[i];
  }

  cout << solve(0, W) << nl;

  return 0;
}
