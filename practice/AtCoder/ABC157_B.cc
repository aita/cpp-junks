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

  vector<vector<ll>> A(3, vector<ll>(3));
  REP(i, 3) {
    REP(j, 3) {
      cin >> A[i][j];
    }
  }
  ll N;
  cin >> N;
  vector<ll> B(N);
  REP(i, N) {
    cin >> B[i];
  }

  vector<vector<bool>> X(3, vector<bool>(3, false));
  REP(i, N) {
    REP(j, 3) {
      REP(k, 3) {
        if (A[j][k] == B[i]) {
          X[j][k] = true;
        }
      }
    }
  }

  REP(i, 3) {
    bool v = true;
    bool h = true;
    REP(j, 3) {
      if (X[i][j] == false)
        h = false;
      if (X[j][i] == false)
        v = false;
    }
    if (v || h) {
      cout << "Yes" << nl;
      return 0;
    }
  }
  bool l = true, r = true;
  REP(i, 3) {
    if (X[i][i] == false) l = false;
    if (X[i][3-i-1] == false) r = false;
  }
  if (l || r) {
    cout << "Yes" << nl;
  } else {
    cout << "No" << nl;
  }

  return 0;
}
