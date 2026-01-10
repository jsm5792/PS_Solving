#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
int a[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    long long ans=0;
    for(int i=N-2;i>=0;i--)
    {
        if(a[i+1] <= a[i])
        {
            ans += a[i]-a[i+1]+1;
            a[i] = a[i+1]-1;
        }
    }
    cout << ans;
}
