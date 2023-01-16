#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[100];
int vis[100][100];

int complexes;
vector<int> ans;

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
            if (vis[i][j] == 1 || board[i][j] == '0')
                continue;
            int area = 1;
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            complexes++;
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
                    if (vis[nx][ny] == 1 || board[nx][ny] == '0')
                        continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                    area++;
                }
            }
            ans.push_back(area);
        }
    }

    cout << complexes << '\n';
    sort(ans.begin(), ans.end());

    for (int i : ans)
        cout << i << '\n';
}