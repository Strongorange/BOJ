#include <bits/stdc++.h>
using namespace std;

int N;
int arr[2000001];
int modify = 1000000;

// dogs
int freq[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int cur = 0;
        cin >> cur;
        arr[cur + modify]++;
    }

    for (int i = 0; i < 2000001; i++)
    {
        if (arr[i] > 0)
        {
            for (int j = 0; j < arr[i]; j++)
            {
                cout << i - modify << '\n';
            }
        }
    }
}

int dogs()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        freq[a + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++)
    {
        while (freq[i]--)
        {
            cout << i - 1000000 << '\n';
        }
    }
}