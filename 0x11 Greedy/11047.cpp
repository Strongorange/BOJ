#include <bits/stdc++.h>
using namespace std;

int n, k;
int coins[10];
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ans = ans + (k / coins[i]);
        k = k % coins[i];
    }

    cout << ans;
}