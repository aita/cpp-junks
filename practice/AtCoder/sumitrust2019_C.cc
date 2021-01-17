#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int X;
    cin >> X;

    int a = X % 100;
    int b = (a-1) / 5 + 1;

    int ans = X / 100 >= b ? 1 : 0;
    cout << ans << endl;

    return 0;
}
