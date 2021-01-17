#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <bitset>
#include <array>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string S;

    cin >> N >> S;

    int ans = 0;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                int A[3] = {i, j, k};
                int found = 0;
                for (auto it = S.begin(); it != S.end(); ++it)
                {
                    if (found <= 2 && (*it - '0') == A[found])
                    {
                        ++found;
                    }
                }
                if (found == 3)
                {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
