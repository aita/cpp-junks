#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    char s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    s1 -= '0';
    s2 -= '0';
    s3 -= '0';

    cout << s1 + s2 + s3 << "\n";

    return 0;
}