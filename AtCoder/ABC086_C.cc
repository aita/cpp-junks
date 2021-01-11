#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> X(N + 1, 0), Y(N + 1, 0), T(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        cin >> T[i] >> X[i] >> Y[i];
    }

    bool failed = false;
    for (int i = 1; i <= N; ++i)
    {
        int dt = T[i] - T[i - 1];
        int dist = abs(X[i] - X[i - 1]) + abs(Y[i] - Y[i - 1]);
        if (dt < dist || dt % 2 != dist % 2)
        {
            failed = true;
            break;
        }
    }

    if (failed)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}
