#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int ans = 0;
int vis[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    vector<int> v;
    for(int i=0;i<M;i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    fill(vis,vis+N+1,-1);
    queue<int> q;
    for(auto i : v)
    {
        vis[i] = 0;
        q.push(i);
    }
    while(!q.empty())
    {
        int curr = q.front();
        ans = max(ans, vis[curr]);
        q.pop();
        for(int i=0;i<20;i++)
        {
            int next = curr ^ (1 << i);
            if(next > N || next < 0)
            {
                continue;
            }
            if(vis[next] != -1)
            {
                continue;
            }
            vis[next] = vis[curr] + 1;
            q.push(next);
        }
    }
    cout << ans;
}
