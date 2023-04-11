#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    vector<int> d(N + 1);
    d[0] = 0;
    d[1] = arr[1];
    d[2] = max(arr[1] + arr[2], arr[2]);

    for (int i = 3; i <= N; i++)
    {
        d[i] = max(d[i - 2], d[i - 3] + arr[i - 1]) + arr[i];
    }

    cout << d[N] << '\n';
}

/*
    1. 테이블 정의
     D[i][j] = 현재까지 j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 점수 합의 최댓값,, 단 i번째 계단은 반드시 밟아야 함

    2. 점화식
     D[k][1] 현재까지 1개의 계단을 연속해서 밝고 k번째 계단까지 올라섰을 때 점수

*/