#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

const int N = 8;
array<int, N> row;
array<bool, N> col;
array<bool, 2*N-1> dpos;
array<bool, 2*N-1> dneg;
array<array<bool, N>, N> X;

void print_board() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (X[i][j] && row[i] != j)
                return;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            auto c = row[i] == j ? "Q" : ".";
            cout << c;
        }
        cout << endl;
    }
}

void solve(int i) {
    if (i == N) {
        print_board();
        return;
    }

    for (int j = 0; j < N; ++j) {
        // (i, j)を取れるクイーンがいたら無視する
        if (col[j] || dpos[i+j] || dneg[i-j+N-1]) {
            continue;
        }
        // (i, j)にクイーンを配置する
        row[i] = j;
        col[j] = dpos[i+j] = dneg[i-j+N-1] = true;
        solve(i+1);
        // (i, j)からクイーンを取り除く
        row[i] = -1;
        col[j] = dpos[i+j] = dneg[i-j+N-1] = false;
    }
}

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        X[r][c] = true;
    }

    fill(row.begin(), row.end(), -1);
    solve(0);

    return 0;
}
