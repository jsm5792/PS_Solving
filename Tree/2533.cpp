#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v[1000005];
int dp[1000005][2];
bool vis[1000005];

void DFS(int curr)
{
    vis[curr] = true;
    dp[curr][0] = 0;
    dp[curr][1] = 1;
    for(int next : v[curr])
    {
        if(vis[next])
        {
            continue;
        }
        DFS(next);
        dp[curr][0] += dp[next][1];
        dp[curr][1] += min(dp[next][0],dp[next][1]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1);
    cout << min(dp[1][0],dp[1][1]);
}
