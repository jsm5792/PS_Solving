#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,S;
int a[100005];
int b[100005];
int ans = 1000005;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for(int i=1;i<=N;i++)
    {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    int end=1;
    for(int i=1;i<=N;i++)
    {
        while(end<=N && b[end]-b[i-1]<S)
        {
            end++;
        }
        if(end>N)
        {
            break;
        }
        ans = min(end+1-i,ans);
    }
    if(ans == 1000005)
    {
        cout << 0;
    }
    else
    {
        cout << ans;
    }
}
