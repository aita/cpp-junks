#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

bool path_finder(string maze) {
  istringstream iss(maze);
  string line;
  vector<vector<char>> m;
  while (getline(iss, line)) {
    m.emplace_back(line.begin(), line.end());
  }
  int n = m.size();
  queue<std::pair<int, int>> queue;
  set<pair<int,int>> visited;
  queue.emplace(0, 0);
  while (!queue.empty()) {
    auto [x, y] = queue.front();
    queue.pop();
    if (visited.find({x, y}) != visited.end()) {
      continue;
    }
    visited.insert({x, y});
    for (auto &[dx, dy]: dirs) {
      int nx = x + dx;
      int ny = y + dy;
      if (nx == n-1 && ny == n-1) return true;
      if (0 <= nx && nx < n && 0 <= ny && ny < n) {
        auto c = m[ny][nx];
        if (c == '.') {
          queue.emplace(nx, ny);
        }
      }
    }
  }
  return false;
}

int main() {
  cout << path_finder(".W.\n.W.\n...") << endl;
}