#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t, n, m, bae;
int board[100][100];
int vis[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> bae;
        for (int i = 0; i < bae; i++)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1 && vis[i][j] == 0)
                {
                    queue<pair<int, int>> Q;
                    vis[i][j] = 1;
                    Q.push({i, j});
                    while (!Q.empty())
                    {
                        pair<int, int> cur = Q.front();
                        Q.pop();
                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || nx >= n; ny < 0 || ny >= m)
                                continue;
                            if (vis[nx][ny] || board[nx][ny] != 1)
                                continue;
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                    num++;
                }
            }
        }
        cout << num << "\n";
        for (int i = 0; i < n; i++)
        {
            fill(board[i], board[i] + m, 0);
            fill(vis[i], vis[i] + m, 0);
        }
    }
    return 0;
}