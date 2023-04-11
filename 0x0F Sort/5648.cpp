#include <bits/stdc++.h>
using namespace std;

int N;
string st;
vector<long long> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> st;
        reverse(st.begin(), st.end());
        v.push_back(stoll(st));
    }

    sort(v.begin(), v.end());

    for (auto i : v)
        cout << i << '\n';
}
