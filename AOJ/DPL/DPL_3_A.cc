#include <iostream>
#include <algorithm>

using namespace std;

// Find Maximum Sub Square Matrix
int main() {
    int h, w;
    cin >> h >> w;

    int G[h][w];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int x;
            cin >> x;
            G[i][j] = x;
        }
    }

    int maxWidth = 0;
    int dp[h][w];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            dp[i][j] = G[i][j] == 0 ? 1 : 0;
            maxWidth |= dp[i][j];
        }
    }

    for (int i = 1; i < h; ++i) {
        for (int j = 1; j < w; ++j) {
            if (!G[i][j]) {
                // 左上、上、左の要素のうち最小の値に1を加えたものが、(i,j)から左上に向かってできる最大の正方形の辺の長さ
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                maxWidth = max(maxWidth, dp[i][j]);
            }
        }
    }
    cout << maxWidth * maxWidth << endl;

    return 0;
}
