#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i] >> B[i];
    }

    long long ans = LLONG_MAX;
    for (int i = 0; i < N; ++i)
    {
        long long S = A[i];
        for (int j = 0; j < N; ++j)
        {
            long long G = B[j];
            long long t = 0;
            for (int k = 0; k < N; ++k)
            {
                long long a = A[k];
                long long b = B[k];
                t += abs(a-S) + abs(b-a) + abs(G-b);
            }
            ans = min(ans, t);
        }
    }

    cout << ans << endl;

    return 0;
}
