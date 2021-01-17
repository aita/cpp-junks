#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int counter = 0;
    for (int i = 0; i <= A; ++i)
    {
        for (int j = 0; j <= B; j++)
        {
            for (int k = 0; k <= C; k++)
            {
                int sum = 500 * i + 100 * j + 50 * k;
                if (sum == X)
                {
                    ++counter;
                }
            }
        }
    }

    cout << counter << "\n";

    return 0;
}