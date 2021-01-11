#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>

using namespace std;
using namespace std::placeholders;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    vector<string> V = {"eraser", "dreamer", "erase", "dream"};

    bool failed = false;
    auto it = S.rbegin();
    while (it != S.rend() && !failed)
    {
        failed = true;
        for (auto &v : V)
        {
            if (equal(v.rbegin(), v.rend(), it))
            {
                it += v.size();
                failed = false;
                break;
            }
        }
    }

    if (failed)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}
