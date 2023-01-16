#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[150][150];
int vis[150][150];

int maxHeight = 0;
int maxArea = 0;

void bfs(int i, int j, int limit)
{
    queue<pair<int, int>> q;
    vis[i][j] = 1;  // 방문표시
    q.push({i, j}); // 푸시
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue; // 정상 범위 체크
            if (vis[nx][ny] == 0 && board[nx][ny] > limit)
            {                     // 미방문, 침수되지 않음
                vis[nx][ny] = 1;  // 첫 방문이라면 방문표시
                q.push({nx, ny}); // 푸시
            }
        }
    }
}

// 높이는 1 ~ 100
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
            // 가장 높은 높이 구하기
            maxHeight = max(board[i][j], maxHeight);
        }
    }

    // 끝에서 || 시작시 vis,  초기화 해줘야할 듯
    // board 는 i 증가 할때마다 덮어씌워져서 초기화 할 필요 없을 듯?
    for (int i = 0; i <= maxHeight; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fill(vis[j], vis[j] + n, 0);
        }

        // 각 높이 (i) 에 대해 bfs 할때마다 area 개수 초기화
        int area = 0;
        // BFS
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                if (board[k][l] > i && vis[k][l] == 0)
                {
                    bfs(k, l, i);
                    area++;
                }
            }
        }
        maxArea = max(area, maxArea);
    }
    cout << maxArea;
}