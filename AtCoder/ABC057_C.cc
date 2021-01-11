#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

uint64_t count_digits(uint64_t n)
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
    cin.tie(0);
    ios::sync_with_stdio(false);

    uint64_t N;
    cin >> N;

    uint64_t A, B;
    uint64_t ans = N;
    for (uint64_t a = 1; a <= sqrt(N); ++a)
    {
        if (N % a != 0)
            continue;

        uint64_t b = N / a;
        ans = min(ans, max(count_digits(a), count_digits(b)));
    }

    cout << ans << endl;

    return 0;
}
