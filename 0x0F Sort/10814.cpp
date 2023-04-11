#include <bits/stdc++.h>
using namespace std;

int N;
bool compareFunc(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<pair<int, string>> arr;

    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        arr.emplace_back(age, name);
    }
    stable_sort(arr.begin(), arr.end(), compareFunc);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
}
