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

    int N, Y;
    cin >> N >> Y;

    int a, b, c;
    a = b = c = -1;
    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= N - i; ++j)
        {
            int k = N - i - j;
            int total = 10000 * i + 5000 * j + 1000 * k;
            if (total == Y)
            {
                a = i;
                b = j;
                c = k;
                break;
            }
        }
    }

    cout << a << " " << b << " " << c << endl;

    return 0;
}
