// BOJ https://www.acmicpc.net/problem/2178
// BAR https://blog.encrypted.gg/941

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[102];
int dist[102][102];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) // board 입력 근데 이 부분 이해 안 감
        cin >> board[i];
    for (int i = 0; i < n; i++) // 2차원 배열 전부 -1 로 초기화
        fill(dist[i], dist[i] + m, -1);
    queue<pair<int, int>> Q; // 큐 생성
    Q.push({0, 0});          // 시작점의 위치 큐에 저장
    dist[0][0] = 0;          // 시작점 (0, 0) 기준으로의 거리를 의미하는 dist 배열의 (0, 0) = 0 <= 시작점이므로 거리 0
    while (!Q.empty())
    {                                   // 큐에 저장된 것이 있으니 큐가 빌때까지 루프
        pair<int, int> cur = Q.front(); // 현재 위치를 나타내는 cur pair 에 큐의 front 저장
        Q.pop();                        // 현재 위치를 저장했으니 큐를 pop
        for (int dir = 0; dir < 4; dir++)
        { // 현재 위치에서 상하좌우 살펴보는 루프
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
                continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; // 시작점 기준으로 위치를 나타내는 배열 dist 의 원소를 현재 값 기준으로 + 1 해줌 (상하좌우의 원소는 현재 위치에서 1만큼 멀어진 위치임을 기억)
            Q.push({nx, ny});                      // 방문한 위치를 큐에 저장
        }
    }
    cout << dist[n - 1][m - 1] + 1; // dist 배열 값에서 + 1을 해준 값이 거리
}