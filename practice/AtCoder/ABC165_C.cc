#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

ll N, M, Q;
vector<ll> a, b, c, d;
vector<ll> A;

ll solve(ll i, ll k) {
  if (i == N) {
    ll score = 0;
    REP(j, Q) {
      if (A[b[j]] - A[a[j]] == c[j])
        score += d[j];
    }
    return score;
  }
  if (k > M)
    return 0;

  A[i] = k;
  return max({
    solve(i+1, k),
    solve(i+1, k+1),
    solve(i, k+1),
  });
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> Q;
  A.reserve(N);
  a.reserve(Q);
  b.reserve(Q);
  c.reserve(Q);
  d.reserve(Q);
  REP(i, Q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i]; --b[i];
  }

  cout << solve(0, 1) << nl;

  return 0;
}
