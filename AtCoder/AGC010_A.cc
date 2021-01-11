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
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int odds = 0;
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        if (*it % 2 != 0)
        {
            ++odds;
        }
    }

    string ans = odds % 2 == 0 ? "YES" : "NO";
    cout << ans << endl;

    return 0;
}
