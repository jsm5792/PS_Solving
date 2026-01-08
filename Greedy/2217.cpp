#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
int a[100003];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans = max(ans,a[n-i]*i);
    }
    cout << ans;
}
