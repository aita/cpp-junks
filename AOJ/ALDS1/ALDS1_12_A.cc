#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int N = 100;

enum {
    WHITE,
    GRAY,
    BLACK,
};

int main() {
    int M[N][N];

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int a;
            cin >> a;
            M[i][j] = a == -1 ? numeric_limits<int>::max() : a;
        }
    }

    // プリム法
    // IN: 頂点集合V, 辺集合E
    // OUT: Vnew, Enew
    vector<int> color(n, WHITE); // 頂点の訪問状態(WHITE:訪問前, BLACK:訪問済)
    vector<int> d(n, numeric_limits<int>::max()); // VnewとVnew-Vの辺集合で重みが最小の辺の重み
    vector<int> p(n, -1); // MSTにおける頂点vの親

    d[0] = 0;
    while (1) {
        int u = -1;
        int minv = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }
        if (u == -1)
            break;
        color[u] = BLACK;

        for (int v = 0; v < n; ++v) {
            if (color[v] != BLACK && M[u][v] != numeric_limits<int>::max()) {
                if (d[v] > M[u][v]) {
                    d[v] = M[u][v];
                    p[v] = u;
                    // color[v] = GRAY;
                }
            }
        }
    }
    int sum;
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1)
            sum += M[i][p[i]];
    }
    cout << sum << endl;

    return 0;
}