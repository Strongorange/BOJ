#include <bits/stdc++.h>
using namespace std;

int N;
string st;
vector<string> v;

bool compareFunc(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    return a.length() < b.length();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> st;
        v.push_back(st);
    }

    sort(v.begin(), v.end(), compareFunc);

    // 중복 단어 제거
    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto i : v)
    {
        cout << i << '\n';
    }
}
