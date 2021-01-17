#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, M;
bool W[100][100];

void dfs(int x, int y)
{
    W[x][y] = false;

    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (W[nx][ny])
                    dfs(nx, ny);
            }
        }
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char c;
            cin >> c;
            W[i][j] = c == 'W';
        }
    }

    int counter = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (W[i][j])
            {
                dfs(i, j);
                ++counter;
            }
        }
    }

    cout << counter << endl;

    return 0;
}
