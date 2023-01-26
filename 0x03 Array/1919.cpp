#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int arr1[26], arr2[26];
int cnt;
int gt, ls;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        arr1[s1[i] - 'a']++;
    }

    for (int i = 0; i < s2.length(); i++)
    {
        arr2[s2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (arr1[i] == arr2[i])
            continue;
        gt = max(arr1[i], arr2[i]);
        ls = min(arr1[i], arr2[i]);
        cnt = cnt + (gt - ls);
        // cout << "gt = " << gt << "   ls = " << ls << "   cnt = " << cnt << "\n";
    }
    cout << cnt;
}