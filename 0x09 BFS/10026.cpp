#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
string board[101];
int vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int area;
int not_g;
int true_g;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                not_g++;
                queue<pair<int, int>> Q;
                Q.push({i, j});
                vis[i][j] = 1;
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (vis[nx][ny] || board[i][j] != board[nx][ny])
                            continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        fill(vis[i], vis[i] + n, 0);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'R')
                board[i][j] = 'G';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j])
            {
                true_g++;
                queue<pair<int, int>> Q;
                Q.push({i, j});
                vis[i][j] = 1;
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (vis[nx][ny] || board[i][j] != board[nx][ny])
                            continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
    }
    cout << not_g << " " << true_g;
}