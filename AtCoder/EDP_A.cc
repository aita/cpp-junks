#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> H(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> H[i];
    }

    vector<int> costs(N, 0);
    costs[0] = 0;
    costs[1] = abs(H[1] - H[0]);
    for (int i = 2; i < N; ++i)
    {
        costs[i] = min(costs[i-2] + abs(H[i] - H[i-2]), costs[i-1] + abs(H[i] - H[i-1]));
    }

    cout << costs[N-1] << endl;

    return 0;
}
