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

    int C[3][3];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> C[i][j];
        }
    }

    bool found = false;
    int A[3], B[3];
    for (int a = 0; a <= C[0][0]; ++a)
    {
        A[0] = a;
        for (int i = 0; i < 3; ++i)
        {
            B[i] = C[0][i] - A[0];
        }

        for (int i = 1; i < 3; ++i)
        {
            A[i] = C[i][0] - B[0];
            for (int j = 0; j < 3; ++j)
            {
                if (A[i] + B[j] != C[i][j])
                {
                    goto next;
                }
            }
        }
        found = true;
        break;

    next:;
    }

    if (found)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
