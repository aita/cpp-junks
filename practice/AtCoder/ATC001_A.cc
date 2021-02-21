#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

ll H, W;
vector<string> C;
set<pair<ll, ll>> visited;
vector<pair<ll, ll>> D = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dfs(ll x, ll y) {
  for (auto [dx, dy] : D) {
    ll nx = x + dx, ny = y + dy;
    if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
    pair<ll, ll> np = {nx, ny};
    if (visited.find(np) != visited.end()) continue;
    visited.insert(np);
    auto c = C[ny][nx];
    if (c == 'g') {
      return true;
    }
    if (c == '.') {
      if (dfs(nx, ny)) return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> H >> W;
  REP(i, H) {
    string s;
    cin >> s;
    C.push_back(s);
  }

  ll sx, sy;
  bool found = false;
  REP(y, H) {
    REP(x, W) {
      auto c = C[y][x];
      if (c == 's') {
        sx = x;
        sy = y;
        found = true;
        break;
      }
    }
    if (found) break;
  }
  string ans = "No";
  if (dfs(sx, sy)) ans = "Yes";
  cout << ans << nl;

  return 0;
}
