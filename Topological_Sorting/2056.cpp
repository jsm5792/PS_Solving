#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,ans;
int dp[10005];
vector <int> v[10005];
int work_time[10005];
int indegree[10005];

void DFS(int curr)
{
    if(dp[curr]!=-1)
    {
        return;
    }
    int max_time = 0;
    for(auto prev : v[curr])
    {
        DFS(prev);
        max_time = max(max_time,dp[prev]);
    }
    dp[curr] = max_time + work_time[curr];

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    fill(dp+1,dp+N+2,-1);
    for(int i=1;i<=N;i++)
    {
        cin >> work_time[i];
        int cnt;
        cin >> cnt;
        for(int j=0;j<cnt;j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for(int i=1;i<=N;i++)
    {
        DFS(i);
        ans = max(ans,dp[i]);
    }
    cout << ans;
}
