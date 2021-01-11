#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdint>
#include <tuple>

using namespace std;

struct point
{
    long long x, y, h;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<point> P;
    for (int i = 0; i < N; ++i)
    {
        long long x, y, h;
        cin >> x >> y >> h;
        point p = {x, y, h};
        P.push_back(p);
    }

    point G = *(find_if(P.begin(), P.end(), [](const point &p) -> bool { return p.h > 0; }));
    long long CX, CY, H;
    for (int i = 0; i <= 100; ++i)
    {
        for (int j = 0; j <= 100; ++j)
        {
            bool found = true;
            long long h = G.h + abs(G.x - i) + abs(G.y - j);
            // h = max(h, 0LL);
            for (int k = 0; k < N; ++k)
            {
                long long hh = h - abs(P[k].x - i) - abs(P[k].y - j);
                hh = max(hh, 0LL);
                if (P[k].h != hh)
                    found = false;
            }

            if (found)
            {
                CX = i;
                CY = j;
                H = h;
                goto end;
            }
        }
    }

end:
    cout << CX << " " << CY << " " << H << endl;

    return 0;
}
