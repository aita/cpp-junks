#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


int main()
{
    using Point = vector<double>;

    int N, D;
    cin >> N >> D;

    vector<Point> X(N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < D; ++j)
        {
            int x;
            cin >> x;
            X[i].push_back(x);
        }
    }

    int ans = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i+1; j < N; ++j)
        {
            double d = 0;
            for (int k = 0; k < D; ++k)
            {
                double x = abs(X[i][k] - X[j][k]);
                d += x*x;
            }
            d = sqrt(d);

            if (d == floor(d))
                ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
