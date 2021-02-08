#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;

/*
k > n, p(k, n) = 0
k = n, p(k, n) = 1
otherwise, p(k, n) = p(k+1, n) + (k, n-k)

p(1, 4) = p(2, 4) + p(1, 3)
        = p(3, 4) + p(2, 2) + p(2, 3) + p(1, 2)
        = p(4, 4) + p(2, 2) + p(3, 3) + p(2, 2) + p(1, 1)
*/
ull exp_sum(unsigned int n) {
  if (n == 0) return 1;
  vector<vector<ull>> dp(n+1, vector<ull>(n+1, 0));
  for (ull i = 1; i <= n; ++i) {
    dp[i][i] = 1;
    for (ull k = i-1; k >= 1; --k) {
      dp[i][k] = dp[i][k+1] + dp[i-k][k];
    }
  }
  return dp[n][1];
}

int main() {
  cout << exp_sum(4) << endl;
  cout << exp_sum(1) << endl;
  cout << exp_sum(2) << endl;
  cout << exp_sum(0) << endl;

  return 0;
}