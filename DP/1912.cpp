#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int a[100005];
int b[100005];
int ans = -1e9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<N;i++)
    {
        b[i] = max(0,b[i-1]) + a[i];
        ans = max(b[i],ans);
    }
    cout << ans;
}
