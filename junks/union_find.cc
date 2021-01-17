#include <numeric>
#include <vector>

class union_find
{
public:
  union_find(std::size_t n) : parent_(n)
  {
    std::iota(parent_.begin(), parent_.end(), 0);
  }

  // xが属する木の根を探索する
  int find(int x)
  {
    if (parent_[x] == x)
      return x;
    return parent_[x] = find(parent_[x]);
  }

  // 木の併合
  void unite(int x, int y)
  {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x == root_y)
      return;
    parent_[root_x] = root_y;
  }

  // 同じ木に属するか
  bool same(int x, int y) { return find(x) == find(y); }

private:
  std::vector<int> parent_;
};