#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    map<int, int> A;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        A[a] += 1;
    }

    int ans = 0;
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        ans += it->second % 2;
    }

    cout << ans << endl;

    return 0;
}
