#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int board[5][5];
int vis[5][5];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    vis[0][0] = 1;
    while (!Q.empty())
    {
        int step = 0;
        pair<int, int> cur = Q.front();
        step = board[cur.X][cur.Y];
        dx[0] = step;
        dy[1] = step;
        Q.pop();
        for (int dir = 0; dir < 2; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    if (vis[n - 1][n - 1] == 1)
        cout << "HaruHaru";
    else
        cout << "Hing";
}
