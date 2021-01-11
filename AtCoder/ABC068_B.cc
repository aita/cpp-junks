#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = 0;
    int h = -1;

    for (int i = 1; i <= N; ++i)
    {
        int c = 0;
        int x = i;
        while (x % 2 == 0 && x > 0)
        {
            ++c;
            x /= 2;
        }

        if (h < c)
        {
            h = c;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}
