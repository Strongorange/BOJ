#include <bits/stdc++.h>
using namespace std;

int x, y, w, h;
int subX, subY;
int minX, minY;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y >> w >> h;
    int subX = w - x;
    int subY = h - y;
    minX = min(x, subX);
    minY = min(y, subY);
    ans = min(minX, minY);

    cout << ans;
}