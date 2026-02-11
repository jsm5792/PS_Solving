#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T,N,K,W;
int build_time[1005];
int dp[1005];
int indegree[1005];
vector <int> v[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> N >> K;
        fill(indegree+1,indegree+N+2,0);
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
            v[x].push_back(y);
            indegree[y]++;
        }
        cin >> W;
        queue<int> q;
        for(int i=1;i<=N;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                dp[i] = build_time[i];
            }            
        }
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            if(curr == W)
            {
                cout << dp[curr] << '\n';
                break;
            }
            for(auto next : v[curr])
            {
                dp[next] = max(dp[next],dp[curr]+build_time[next]);
                indegree[next]--;
                if(indegree[next]==0)
                {
                    q.push(next);
                }
            }
        }
    }
}
