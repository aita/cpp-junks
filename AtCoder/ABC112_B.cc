#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int ans = 0;
    int len = 0;
    for (auto it = S.begin(); it != S.end(); ++it)
    {
        char c = *it;
        switch (c) {
        case 'A':
        case 'C':
        case 'G':
        case 'T':
            ++len;
            ans = max(ans, len);
            break;

        default:
            len = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
