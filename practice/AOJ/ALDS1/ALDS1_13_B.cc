#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>


using namespace std;

const int N = 3;

struct Puzzle {
    array<array<int, N>, N> board;
    array<int, 2> empty;
    int turn;

    bool operator < (const Puzzle &p) const {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != p.board[i][j])
                    return board[i][j] < p.board[i][j];
            }
        }
        return false;
    }
};


vector<array<int, 2>> dir = {
    {-1, 0}, // left
    {0, -1}, // up
    {1, 0},  // right
    {0, 1},  // down
};

bool solved(const Puzzle& p) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int x = i == 2 && j == 2 ? 0 : i * 3 + j + 1;
            if (p.board[i][j] != x) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    Puzzle start;
    start.turn = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            if (x == 0) {
                start.empty = {i, j};
            }
            start.board[i][j] = x;
        }
    }

    Puzzle ans;
    set<Puzzle> visited;
    queue<Puzzle> Q;
    Q.push(start);
    while (!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        if (solved(u)) {
            ans = u;
            break;
        }
        for (auto& d : dir) {
            auto tx = u.empty[0] + d[0];
            auto ty = u.empty[1] + d[1];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N) {
                continue;
            }
            auto v = u;
            swap(v.board[v.empty[0]][v.empty[1]], v.board[tx][ty]);
            v.empty = {tx, ty};
            if (visited.find(v) == visited.end()) {
                ++v.turn;
                visited.insert(v);
                Q.push(v);
            }
        }
    }
    cout << ans.turn << endl;

    return 0;
}