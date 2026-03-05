#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
long long fibo[95];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2;i<=N;i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    cout << fibo[N];
}
