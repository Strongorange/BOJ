#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
string board[2000];
int dist1[2000][2000];
int dist2[2000][2000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> board[i];

    for (int i = 0; i < n; i++)
    {
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }

    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'F')
            {
                Q1.push({i, j});
                dist1[i][j] = 0;
            }
            if (board[i][j] == 'J')
            {
                Q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }
    // 불의 BFS
    while (!Q1.empty())
    {
        pair<int, int> cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= 0 || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == '#' || dist1[nx][ny] >= 0)
                continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }
    // J 의 BFS
    while (!Q2.empty())
    {
        pair<int, int> cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            if (board[nx][ny] == '#' || dist2[nx][ny] >= 0)
                continue;
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
                continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}