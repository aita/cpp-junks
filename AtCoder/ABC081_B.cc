#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;
using namespace std::placeholders;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int c = 0;
    while (1)
    {
        auto it = find_if(A.begin(), A.end(), [](int a) -> int { return a % 2 == 1; });
        if (it != A.end())
            break;

        transform(A.begin(), A.end(), A.begin(), bind(divides<int>(), _1, 2));
        ++c;
    }

    cout << c << "\n";

    return 0;
}