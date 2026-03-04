#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
pair<int,int> a[13];
int ans;
int cnt;

void solve(int x)
{
    if(x==N)
    {
        ans = max(ans,cnt);
        return;                
    }
    if(a[x].first <=0 || cnt == N-1)
    {
        solve(x+1);
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(i==x || a[i].first<=0)
        {
            continue;
        }
        a[i].first -= a[x].second;
        a[x].first -= a[i].second;
        if(a[i].first <= 0)
        {
            cnt++;
        }
        if(a[x].first <= 0)
        {
            cnt++;
        }
        solve(x+1);
        if(a[i].first <= 0)
        {
            cnt--;
        }
        if(a[x].first <= 0)
        {
            cnt--;
        }
        a[i].first += a[x].second;
        a[x].first += a[i].second;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    solve(0);
    cout << ans;
}
