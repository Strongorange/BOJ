#include <bits/stdc++.h>
using namespace std;

// S 층에서 G 층으로 가기 위해서 눌러야하는 버튼의 수의 최소값
// U 버튼 누르면 U 층만큼 올라가고 D 버튼 누르면 D 층 만큼 내려감
int F, S, G, U, D;
int board[2000000];
int dist[2000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;
    fill(dist + 1, dist + 1 + F, -1);
    dist[S] = 0;
    queue<int> Q;
    Q.push(S);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (int nxt : {cur + U, cur - D})
        {
            if (nxt <= 0 || nxt > F)
                continue;
            if (dist[nxt] != -1)
                continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }

    if (dist[G] == -1)
        cout << "use the stairs";
    else
        cout << dist[G];
}