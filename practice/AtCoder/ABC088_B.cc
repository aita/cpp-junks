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

    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> a[i];
        // cerr << a[i] << endl;
    }

    int Alice = 0;
    int Bob = 0;

    sort(a.begin(), a.end(), greater<>());
    for (int i = 0; i < N; ++i)
    {
        if (i % 2 == 0)
        {
            Alice += a[i];
        }
        else
        {
            Bob += a[i];
        }
    }

    cout << Alice - Bob << "\n";

    return 0;
}