#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> v(N);
    vector<int> w(N);
    for (int i = 0; i < N; ++i) {
        int vi, wi;
        cin >> vi >> wi;
        v[i] = vi;
        w[i] = wi;
    }

    // 0-1 Knapsack Problem
    vector<int> dp(W+1, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = W; j >= w[i]; --j) {
            dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
        }
    }
    cout << dp.back() << endl;

    return 0;
}