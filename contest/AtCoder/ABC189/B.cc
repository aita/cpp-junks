#include <bits/stdc++.h>
#include <numeric>

using namespace std;

using int64 = long long;

#define FOR(i, a, b)                                                           \
  for (int64 i = static_cast<int64>(a); i < static_cast<int64>(b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, X;
  cin >> N >> X;
  vector<int64> V(N), P(N);
  REP(i, N)
  {
    cin >> V[i] >> P[i];
  }

  int ans = -1;
  int64 x = 0;
  REP(i, N)
  {
    x += V[i] * P[i];
    if (x > X * 100)
    {
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;

  return 0;
}
