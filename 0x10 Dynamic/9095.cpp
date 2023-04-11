#include <bits/stdc++.h>
using namespace std;

int d[20];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for (int i = 4; i < 11; i++)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}

/*
1, 테이블 정의
D[i] = i를 1, 2, 3의 합으로 나타내는 방법의 수
*/