#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <set>
#include <queue>

using namespace std;

const int N = 4;
const int N2 = N * N;

int MDT[N2][N2];

struct Puzzle {
    array<char, N2> board;
    int empty;
    int cost;
    int rank;

    bool operator < (const Puzzle& other) const {
        return cost + rank > other.cost + other.rank;
    }
};

int distance(const Puzzle& p) {
    int d = 0;
    for (int i = 0; i < N2; ++i) {
        if (p.board[i] == N2) continue;
        d += MDT[i][p.board[i] - 1];
    }
    return d;
}

const vector<array<int, 2>> dir = {
    {-1, 0}, // left
    {0, -1}, // up
    {1, 0},  // right
    {0, 1},  // down
};

int astar(Puzzle start) {
    auto puzzle_less = [](const Puzzle& a, const Puzzle& b) {
        for (int i = 0; i < N2; ++i) {
            if (a.board[i] != b.board[i])
                return a.board[i] < b.board[i];
        }
        return false;
    };

    Puzzle ans;
    set<Puzzle, decltype(puzzle_less)> visited(puzzle_less);
    priority_queue<Puzzle> Q;
    Q.push(start);
    while (!Q.empty()) {
        auto u = Q.top();
        Q.pop();
        if (u.rank == 0) {
            return u.cost;
        }
        visited.insert(u);

        auto sx = u.empty % N;
        auto sy = u.empty / N;
        for (auto& d : dir) {
            auto tx = sx + d[0];
            auto ty = sy + d[1];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N) {
                continue;
            }
            auto v = u;

            auto k = tx + ty * N;
            swap(v.board[v.empty], v.board[k]);
            v.empty = k;
            v.rank = distance(v);
            if (visited.find(v) == visited.end()) {
                ++v.cost;
                Q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    for (int i = 0; i < N2; ++i) {
        for (int j = 0; j < N2; ++j) {
            // iからjへのマンハッタン距離
            MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
        }
    }

    Puzzle start;
    for (int i = 0; i < N2; ++i) {
        int x;
        cin >> x;
        start.board[i] = x;
        if (x == 0) {
            start.board[i] = N2;
            start.empty = i;
        }
    }
    start.cost = 0;
    start.rank = distance(start);
    cout << astar(start) << endl;

    return 0;
}