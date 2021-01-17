#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<vector<long long>> A;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        vector<long long> a(M);
        for (int j = 0; j < M; ++j)
        {
            cin >> a[j];
        }
        A.push_back(a);
    }

    long long ans = 0;
    for (int i = 0; i < M-1; ++i)
    {
        for (int j = i+1; j < M; ++j)
        {
            long long total = 0;
            for (int k = 0; k < N; ++k)
            {
                total += max(A[k][i], A[k][j]);
            }
            ans = max(ans, total);
        }
    }

    cout << ans << endl;

    return 0;
}
