#include <iostream>
#include <vector>

using namespace std;

bool binary_search(const vector<int> &v, int key)
{
    size_t min = 0;
    size_t max = v.size() - 1;

    while (max - min > 1)
    {
        size_t mid = min + (max - min) / 2;
        if (v[mid] == key)
        {
            return true;
        }
        if (v[mid] < key)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> S(n);
    for (size_t i = 0; i < n; ++i)
    {
        cin >> S[i];
    }

    int q;
    cin >> q;
    int C = 0;
    for (size_t i = 0; i < q; ++i)
    {
        int t;
        cin >> t;
        if (binary_search(S, t))
            ++C;
    }

    cout << C << endl;

    return 0;
}