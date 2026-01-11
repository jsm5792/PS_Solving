#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin >> N >> K;
    long long ans = 1;
    for(int i=N;i>=N-K+1;i--)
    {
        ans *= i;
    }
    for(int i=1;i<=K;i++)
    {
        ans /= i;
    }
    cout << ans;
}
