#include <bits/stdc++.h>
using namespace std;

string st;
vector<string> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> st;
    int counter = st.size();

    for (int i = 0; i < counter; i++)
    {
        string temp;
        temp = st.substr(i);
        arr.emplace_back(temp);
    }

    stable_sort(arr.begin(), arr.end());

    for (auto a : arr)
    {
        cout << a << '\n';
    }
}