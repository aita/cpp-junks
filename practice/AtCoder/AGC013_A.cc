#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std;
using namespace std::placeholders;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int counter = 1;
    int direction = 0;
    for (auto it = A.begin() + 1; it != A.end(); ++it)
    {
        auto last = it - 1;

        if (*it == *last)
            continue;

        if (direction == 0)
        {
            direction = *it < *last ? -1 : 1;
        }
        else if (direction == -1 && *it < *last)
        {
            continue;
        }
        else if (direction == 1 && *it > *last)
        {
            continue;
        }
        else
        {
            direction = 0;
            ++counter;
        }
    }

    cout << counter << endl;

    return 0;
}
