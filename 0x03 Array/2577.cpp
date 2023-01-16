#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int multiple;
vector<int> V(10);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    multiple = a * b * c;

    while (multiple > 0)
    {
        V[multiple % 10]++;
        multiple /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << V[i] << '\n';
    }
}
