#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>

using namespace std;
using namespace std::placeholders;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    // ABを買わない
    int a1 = A * X + B * Y;

    // ABだけ買う
    int i = max(X, Y);
    int a2 = i * (2 * C);

    // 余らないようにABを買う
    int j = min(X, Y);
    int a3 = j * (2 * C) + A * max(0, X - j) + B * max(0, Y - j);

    int total = min(a1, min(a2, a3));

    cout << total << endl;

    return 0;
}
