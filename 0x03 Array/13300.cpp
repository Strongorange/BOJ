#include <bits/stdc++.h>
using namespace std;

int n, k, s, y, rooms;
int arr[2][6];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> y;
        arr[s][y - 1]++;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            rooms = rooms + ceil((double)arr[i][j] / k);
        }
    }

    cout << rooms;
}