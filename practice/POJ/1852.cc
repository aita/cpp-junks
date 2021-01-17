#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int C;
    cin >> C;

    for (int i = 0; i < C; ++i)
    {
        int L, N;
        cin >> L >> N;

        vector<int> ants(N);
        for (int j = 0; j < N; ++j)
        {
            cin >> ants[j];
        }

        int tmax = 0, tmin = 0;
        for (int k = 0; k < N; ++k)
        {
            int x = ants[k];
            tmin = max(tmin, min(x, L - x));
            tmax = max(tmax, max(x, L - x));
        }
        cout << tmin << " " << tmax << "\n";
    }

    return 0;
}