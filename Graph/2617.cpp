#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> v1[105];
vector<int> v2[105];
bool visit[105];

int BFS(int x,vector<int> v[])
{
    fill(visit,visit+N+1,false);
    queue<int> q;
    q.push(x);
    visit[x] = true;
    int count = 0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto next : v[curr])
        {
            if(visit[next])
            {
                continue;
            }
            visit[next] = true;
            count++;
            q.push(next);
        }
    }
    return count;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while(M--)
    {
        int x,y;
        cin >> x >> y;
        v1[x].push_back(y);
        v2[y].push_back(x);
    }
    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        if(BFS(i,v1) >= (N+1)/2 || BFS(i,v2) >= (N+1)/2)
        {
            ans++;
        } 
        
    }
    cout << ans;
}
