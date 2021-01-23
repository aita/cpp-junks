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

  string S;
  cin >> S;
  if (S[0] == S[1] && S[1] == S[2])
  {
    cout << "Won\n";
  }
  else
  {
    cout << "Lost\n";
  }

  return 0;
}
