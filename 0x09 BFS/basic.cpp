#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <deque>
#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int board[502][502] =
    {
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}; // 보드 자체 2차원 배열로 이루어짐
bool vis[502][502];                      // 방문 여부를 저장하는 배열 수업에서의 검은 원
int n = 7, m = 10;                       // 보드의 크기
int dx[4] = {1, 0, -1, 0};               // 상하좌우 네 방향을 의미
int dy[4] = {0, 1, 0, -1};               // 행 (세로) 는 x, 열 (가로) 가 y )

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int, int>> Q;
    vis[0][0] = 1;  // (0, 0)을 방문했다고 명시
    Q.push({0, 0}); // 큐에 시작점 (0, 0)을 삽입

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();                     // 현재 위피, 큐의 가장 앞쪽을 현재 위치에 저장
        Q.pop();                                            // 현재 위치를 cur 에 저장 후 큐에서는 pop 시킴
        cout << '(' << cur.X << ", " << cur.Y << ") -> \n"; // cur 의 X, Y 위치를 살펴보기 위한 출력문
        for (int dir = 0; dir < 4; dir++)
        { // 상하좌우 4방향을 살펴보기 위한 반목문, dir < 4 는 4 방향이기 때문에
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];                   // 하우상좌 순서로 인접한 칸의 좌표가 nx, ny에 저장
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) // n * m (7 * 10) 의 보드 범위를 넘어가는 경우 패스
                continue;
            if (vis[nx][ny] || board[nx][ny] != 1) // 이미 방문한 칸이거나 1이 아닌 (파란 칸이 아닌) 경우에 패스
                continue;
            vis[nx][ny] = 1;  //(nx, ny) 를 방문했다고 명시
            Q.push({nx, ny}); // 큐에 nx, ny 저장
        }
    }
}