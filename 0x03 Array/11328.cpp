#include <bits/stdc++.h>
using namespace std;

int n;
string s1;
string s2;
int acc[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> s1 >> s2;
        fill(acc, acc + 26, 0);
        bool flag = true;

        for (int i = 0; i < s1.length(); i++)
        {
            acc[s1[i] - 'a']++;
            acc[s2[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (acc[i] != 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}