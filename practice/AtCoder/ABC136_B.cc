#include <iostream>

using namespace std;

int count_digits(int n)
{
    int count = 0;
    while (n != 0)
    {
        ++count;
        n /= 10;
    }
    return count;
}


int main()
{
    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (count_digits(i) % 2 == 1)
        {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}