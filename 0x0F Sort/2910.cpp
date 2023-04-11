#include <bits/stdc++.h>
using namespace std;

int N, C;

bool compareFunc(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;
    vector<pair<int, int>> arr; // pair : {cnt, num}
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        bool chk = false;
        for (auto a : arr)
        {
            if (a.second == x)
            {
                chk = true;
                a.first++;
                break;
            }
        }
        if (!chk)
            arr.push_back({1, x});
    }
    sort(arr.begin(), arr.end(), compareFunc);

    for (auto b : arr)
    {
        while (b.first--)
            cout << b.second << ' ';
    }
}
