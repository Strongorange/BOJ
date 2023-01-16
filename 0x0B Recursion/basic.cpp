#include <bits/stdc++.h>
using namespace std;

// func1
// func1(1) 이 1을 출력한다.
// func1(k) 가 k k-1 k-2 ... 1 을 출력하면
// func1(k+1) 은 k+1 k k-1 ... 1 을 출력한다
// k + 1 출력 => func1(k) 호출 = k k-1 k-2 ... 1 출력
void func1(int N)
{
    if (N == 0)
        return;
    cout << N << " ";
    func1(N - 1);
}

// func2
//
int func2(int N)
{
    if (N == 0)
        return 0;
    return N + func2(N - 1);
}

// 재귀는 시간복잡에서 상당히 손해를 볼 수도 있음의 예시 n = 100 이면 2000년 걸림
// 이 함수의 시간복잡도는 O(1.617^N)
int fibo(int n)
{
    if (n <= 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int func3(int a, int b, int m)
{
    int val = 1;
    while (b--)
        val *= a;
    return val;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = func3(2, 3, 1);
    cout << ans;
}