#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int board[400][400];
int dist[400][400];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, 2};
int t, n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            fill(dist[i], dist[i] + n, -1);
        }
        pair<int, int> start;
        pair<int, int> dest;
        cin >> start.X >> start.Y;
        cin >> dest.X >> dest.Y;
        queue<pair<int, int>> Q;
        Q.push({start.X, start.Y});
        dist[start.X][start.Y] = 0;
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                    continue;
                if (dist[nx][ny] >= 0)
                    continue;
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
        cout << dist[dest.X][dest.Y] << "\n";
    }
}