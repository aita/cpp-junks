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
  vector<string> S(N);
  REP(i, N){
      cin >> S[i];
  }
  int64 T = 1;
  int64 F = 1;
  REP(i, N)
  {
    if (S[i] == "AND")
    {
      T = T;
      F = F * 2LL + T;
    }
    else
    {
      T = T * 2LL + F;
      F = F;
    }
  }
  cout << T << endl;

  return 0;
}
