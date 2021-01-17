#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> X(3);
    cin >> X[0] >> X[1] >> X[2];
    sort(X.begin(), X.end());

    int d1 = X[2] - X[0];
    int d2 = X[2] - X[1];

    int ans = d1 / 2 + d2 / 2;
    switch (d1 % 2 + d2 % 2)
    {
    case 0:
        break;
    case 1:
        ans += 2;
        break;
    case 2:
        ans += 1;
        break;
    };

    cout << ans << endl;

    return 0;
}
