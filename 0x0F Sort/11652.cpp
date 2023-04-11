#include <bits/stdc++.h>
using namespace std;

int N;
long long arr[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int cnt = 0;
    long long mxval = -(1ll << 62) - 1;
    int mxcnt = 0;

    for (int i = 0; i < N; i++)
    {
        if (i == 0 || arr[i - 1] == arr[i])
            cnt++;
        else
        {
            if (cnt > mxcnt)
            {
                mxcnt = cnt;
                mxval = arr[i - 1];
            }
            cnt = 1;
        }
    }
    if (cnt > mxcnt)
        mxval = arr[N - 1];
    cout << mxval;
}