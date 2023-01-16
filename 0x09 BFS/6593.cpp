#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
const int MX = 31;

int l, n, m;
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dh[6] = {0, 0, 0, 0, 1, -1};
string board[100];
int vis[100][100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> l >> n >> m;
        if (l == 0 && n == 0 && m == 0)
            break;
        queue<tuple<int, int, int>> Q;
        char board[MX][MX][MX];
        int dist[MX][MX][MX];
        bool isEscape = false;

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fill(dist[i][j], dist[i][j] + m, 0);
            }
        }

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < m; k++)
                {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S')
                    {
                        Q.push({i, j, k});
                        dist[i][j][k] = 0;
                    }
                    else if (board[i][j][k] == '.')
                        dist[i][j][k] = -1;
                }
            }
        }

        while (!Q.empty())
        {
            if (isEscape)
                break;
            tuple<int, int, int> cur = Q.front();
            Q.pop();
            int curH, curX, curY;
            tie(curH, curX, curY) = cur;
            for (int dir = 0; dir < 6; dir++)
            {
                int nh = curH + dh[dir];
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || nh < 0 || nh >= l)
                    continue;
                if (board[nh][nx][ny] == '#' || dist[nh][nx][ny] > 0)
                    continue;
                dist[nh][nx][ny] = dist[curH][curX][curY] + 1;
                if (board[nh][nx][ny] == 'E')
                {
                    cout << "Escaped in " << dist[nh][nx][ny] << " minutes(s).\n";
                    isEscape = true;
                    break;
                }
                Q.push({nh, nx, ny});
            }
        }
        while (!Q.empty())
            Q.pop();
        if (!isEscape)
            cout << "Trapped!"
                 << "\n";
    }
}
