#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>

using namespace std;
using namespace std::placeholders;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A, B;

    cin >> N >> A >> B;

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        int x = 0;
        int n = i;
        while (n > 0)
        {
            x += n % 10;
            n /= 10;
        }
        if (A <= x && x <= B)
        {
            ans += i;
        }
    }

    cout << ans << "\n";

    return 0;
}