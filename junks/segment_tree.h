#include <iostream>
#include <limits>
#include <vector>

class segment_tree
{
private:
    static std::size_t power_of_two(std::size_t k)
    {
        std::size_t n = 1;
        while (n < k)
            n *= 2;
        return n;
    }

public:
    segment_tree(std::size_t n)
        : n_(power_of_two(n)), nodes_(2 * n_ - 1, std::numeric_limits<int>::max()) {}

    segment_tree(const std::vector<int> &v) : segment_tree(v.size())
    {
        // 最下段に値をコピーする
        for (std::size_t i = 0; i < v.size(); i++)
        {
            nodes_[i + n_ - 1] = v[i];
        }
        // 下から左右の子の最小値をコピーしていく
        for (std::size_t i = n_ - 2; i >= 0; --i)
        {
            nodes_[i] = std::min(nodes_[2 * i + 1], nodes_[2 * i + 2]);
        }
    }

    void update(std::size_t i, int x)
    {
        // 最下段のノードの添字
        i += n_ - 1;

        // 最下段のノードから、親ノードを辿っていく
        nodes_[i] = x;
        while (i > 0)
        {
            // 親ノードの添字
            i = (i - 1) / 2;
            // 左右のminで親ノードの値を更新する
            nodes_[i] = std::min(nodes_[2 * i + 1], nodes_[2 * i + 2]);
        }
    }

    int query(std::size_t a, std::size_t b) { return query(a, b, 0, 0, n_); }

    int query(std::size_t a, std::size_t b, std::size_t k, std::size_t l,
              std::size_t r)
    {
        // [l, r) が [a, b) と重ならない
        if (r <= a || b <= l)
        {
            return std::numeric_limits<int>::max();
        }
        // [l, r) が [a, b) の範囲で収まる
        if (a <= l && r <= b)
        {
            return nodes_[k];
        }
        // 区間の一部が重なるので、左右の子を探索する
        int x = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左側 [l, (l+r)/2)
        int y = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右側 [(l+r)/2, r)
        return std::min(x, y);
    }

private:
    std::size_t n_;
    std::vector<int> nodes_;
};
