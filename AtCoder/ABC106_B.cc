#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <cstdint>
#include <tuple>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = 0;

    for (int i = 1; i <= N; i+=2)
    {
        int c = 1;
        for (int k = 1; k < i/2; ++k)
        {
            if (i % k == 0) {
                ++c;
            }
        }
        if (c == 8) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
