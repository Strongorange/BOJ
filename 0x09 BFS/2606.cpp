#include <bits/stdc++.h>
using namespace std;

vector<int> board[110];
int vis[110];
int cnt = 0;

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }

    queue<int> Q;
    Q.push(1);
    vis[1] = 1;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int i = 0; i < board[cur].size(); i++)
        {
            int nxt = board[cur][i];
            if (nxt < 0 || nxt > n)
                continue;
            if (vis[board[cur][i]])
                continue;
            vis[nxt] = 1;
            Q.push(nxt);
            cnt++;
        }
    }

    cout << cnt << "\n";
}
