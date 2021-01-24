#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;

#define FOR(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll N;
  cin >> N;
  vector<ll> A(N);
  REP(i, N)
  {
    cin >> A[i];
  }

  bool ans = all_of(A.begin(), A.end(), [](ll a) -> bool {
    if (a % 2 == 0)
      return a % 3 == 0 || a % 5 == 0;
    else
      return true;
  });
  if (ans) {
    cout << "APPROVED\n";
  } else {
    cout << "DENIED\n";
  }

  return 0;
}
