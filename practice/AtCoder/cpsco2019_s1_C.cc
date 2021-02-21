#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";

ll N, K;
vector<ll> A;
vector<ll> C;

ll number_of_coins(ll n) {
  ll i = 0;
  for (auto c : C) {
    if (n >= c) {
      i += n / c;
      n = n % c;
    }
  }
  return i;
}

ll solve(ll i, ll j, ll total) {
  if (i == K) {
    return number_of_coins(total);
  }
  if (j >= N) {
    return INF;
  }
  return min({
    solve(i+1, j+1, total + A[j]),
    solve(i, j+1, total),
  });
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll c = 1;
  REP(i, 9) {
    C.push_back(c);
    C.push_back(c * 5);
    c *= 10;
  }
  sort(C.begin(), C.end(), greater<ll>());

  cin >> N >> K;
  REP(i, N) {
    ll a;
    cin >> a;
    A.push_back(a);
  }

  cout << solve(0, 0, 0) << nl;

  return 0;
}
