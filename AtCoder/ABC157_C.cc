#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
vector<int> S, C;

bool ok(string const& s)
{
    if (s.size() != N)
        return false;

    for (int i = 0; i < M; ++i)
    {
        int d = s[S[i]-1] - '0';
        if (d != C[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> N >> M;

    S.reserve(M);
    C.reserve(M);
    for (int i = 0; i < M; ++i)
    {
        cin >> S[i] >> C[i];
    }

    int ans = -1;
    for (int i = 0; i < 1000; ++i)
    {
        string s = to_string(i);
        if (ok(s))
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}