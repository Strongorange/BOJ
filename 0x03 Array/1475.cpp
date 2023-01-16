#include <bits/stdc++.h>
using namespace std;

int roomNum, ans = 1;
vector<int> nums(10);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> roomNum;
    while (roomNum > 0)
    {
        nums[roomNum % 10]++;
        roomNum /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
            continue;
        ans = max(ans, nums[i]);
    }

    ans = max(ans, (nums[6] + nums[9] + 1) / 2);
    cout << ans;
}
