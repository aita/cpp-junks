#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using ll = long long;
constexpr auto INF = numeric_limits<ll>::max();

#define RANGE(i, a, b)                                                           \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define REP(i, n) RANGE(i, 0, n)

constexpr auto nl = "\n";


#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using bigint = mp::cpp_int;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string X;
  ll M;
  cin >> X >> M;

  ll d = 0;
  REP(i, X.size()) {
    d = max(d, (ll)X[i] - '0');
  }
  cout << d << nl;

  ll ans = 0;
  while (true) {
    ll x = stoll(X, nullptr, ++d);
    if (x > M) {
      break;
    }
    ++ans;
  }

  cout << ans << nl;

  return 0;
}
