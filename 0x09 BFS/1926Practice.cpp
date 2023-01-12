// BOJ https://www.acmicpc.net/problem/1926c
// BAR https://blog.encrypted.gg/941
#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int board[502][502];
bool vis[502][502];        // 방문 여부를 저장하는 배열 수업에서의 검은 원
int n, m;                  // 보드의 크기
int dx[4] = {1, 0, -1, 0}; // 상하좌우 네 방향을 의미
int dy[4] = {0, 1, 0, -1}; // 행 (세로) 는 x, 열 (가로) 가 y )

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; // n 은 세로칸 m 은 가로 칸
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j]; // 보드의 행(x 값) 열(y 값) 을 받아서 보드 초기화
        }
    }
    int mx = 0;  // 그림의 최대값
    int num = 0; // 그림의 수

    for (int i = 0; i < n; i++)
    { // 2중 for 문을 돌며 (i, j) 가 BFS 의 시작점이 될 수 있는지 확인 함
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0 || vis[i][j])
                continue; // 시작점이 될 수 없다면 continue 로 다음 j 로 넘어감
            num++;        // BFS 의 시작점을 찾았음으로 새로운 그림 발견, (0,0)에서 시작해서 쭉 순회하며 visit 값을 찍으며 BFS 가 진행되어 위의 if 문을 통과한 친구들은 반드시 BFS 의 시작점
            queue<pair<int, int>> Q;
            vis[i][j] = 1;
            Q.push({i, j});
            int area = 0; // 크기 (BFS 를 이루는 1칸의 크기들 사격형의 넓이가 아님!!!)
            while (!Q.empty())
            {
                area++;                         // BFS 를 이루는 1칸의 숫자 증가, 사각형의 넓이가 아님
                pair<int, int> cur = Q.front(); // 현재 위치에 큐의 가장 앞쪽 저장
                Q.pop();                        // 현재 위치를 저장했으니 가장 앞쪽 pop
                for (int dir = 0; dir < 4; dir++)
                { // 현재 위치의 하우상좌 순서로 인접한 값들 확인
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue; // 하우상좌 의 위치가 보드 값을 넘어가는 범위일시 건너뜀
                    if (vis[nx][ny] || board[nx][ny] != 1)
                        continue;     // 하우상좌 위치가 이미 방문한 곳이거나 보드상에서 0 인 경우에 건너뜀
                    vis[nx][ny] = 1;  // 방문 표시 남김
                    Q.push({nx, ny}); // 큐에 하우상좌 위치 중 조건에 부합하는 곳을 큐에 삽입
                }
            }
            mx = max(mx, area); // 2중 for 문에서 y 값에 해당하는 2번째 for 문이 끝날을때는 (n, m) 좌표에서 하우상좌 위치를 모두 검증 후 max 값 업데이트
        }
    }
    cout << num << "\n"
         << mx; // 2중 for 문이 모두 끝난 후, 보드의 모든 원소에대해 BFS 종료 후 그림의 개수와 가장 넓은 그림의 넓이 출력
}