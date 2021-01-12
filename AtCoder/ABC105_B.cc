#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    bool ans = false;
    for (int i = 0; i <= N / 4; ++i)
    {
        for (int j = 0; j <= N / 7; ++j)
        {
            if (4*i + 7*j == N)
            {
                ans = true;
            }
        }
    }

    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}