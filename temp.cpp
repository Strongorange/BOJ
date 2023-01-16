#include <bits/stdc++.h>
using namespace std;

bool flag = false;
int sum;
int smalls[9];
string wowwow[5];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        cin >> wowwow[i];
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << (wowwow[i][j] - '0') << "\n";
        }
    }
}