#include <bits/stdc++.h>
using namespace std;

int n, x, ans;
vector<int> V(1000010);
vector<int> nums(2000010);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> V[i];
    }

    cin >> x;

    for (int i = 1; i <= n; i++)
    {
        int number = V[i];
        if (x - number > 0 && nums[x - number])
            ans++;
        nums[number] = 1;
    }
    cout << ans;
}
