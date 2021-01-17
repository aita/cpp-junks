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

    int N;
    cin >> N;

    set<int> d;
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        d.insert(x);
    }
    auto ans = d.size();
    cout << ans << "\n";

    return 0;
}
