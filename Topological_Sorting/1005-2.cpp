#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T,N,K,W;
int build_time[1005];
int dp[1005];
vector <int> v[1005];

int DFS(int curr)
{
    if(dp[curr]!=-1)
    {
        return dp[curr];
    }
    if(v[curr].empty())
    {
        dp[curr] = build_time[curr];
        return dp[curr];
    }
    int max_time = 0;
    for(auto prev : v[curr])
    {
        max_time = max(max_time,DFS(prev));
    }
    dp[curr] = max_time + build_time[curr];
    return dp[curr];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        fill(dp+1,dp+N+2,-1);
        fill(build_time+1,build_time+N+2,0);
        for(int i=1;i<=N;i++)
        {
            v[i].clear();
            cin >> build_time[i];
        }
        for(int i=0;i<K;i++)
        {
            int x,y;
            cin >> x >> y;
            v[y].push_back(x);
        }
        cin >> W;
        cout << DFS(W) <<'\n';
    }
}
