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

  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N)
  {
    cin >> A[i];
  }

  int ans = 0;
  REP(i, N)
  {
    int a = A[i];
    int c = 0;
    int n = 1;
    REP(j, N)
    {
      if (A[j] >= a)
      {
        ++c;
      } else {
        n = max(n, c);
        c = 0;
      }
    }
    n = max(n, c);
    ans = max(ans, a * n);
  }
  cout << ans << endl;

  return 0;
}
