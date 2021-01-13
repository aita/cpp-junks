#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

// Find Maximum Size Rectangle
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

    int dp[h][w+1];
    fill(&dp[0][0], &dp[h-1][w] + 1, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!G[i][j]) {
                dp[i][j] = i > 0 ? dp[i-1][j] + 1 : 1;
            }
        }
    }

    int maxv = 0;
    stack<pair<int, int>> S;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j <= w; ++j) {
            auto rect = make_pair(dp[i][j], j);
            if (S.empty()) {
                S.push(rect);
            } else {
                if (S.top().first < rect.first) {
                    S.push(rect);
                } else if (S.top().first > rect.first) {
                    auto pos = j;
                    while (!S.empty() && S.top().first >= rect.first)  {
                        auto pre = S.top(); S.pop();
                        auto area = pre.first * (j - pre.second);
                        maxv = max(maxv, area);
                        pos = pre.second;
                    }
                    rect.second = pos;
                    S.push(rect);
                }
            }
        }
    }
    cout << maxv << endl;

    return 0;
}
