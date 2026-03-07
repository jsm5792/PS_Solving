#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int f,s,g,u,d;
int dist[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> f >> s >> g >> u >> d;
    fill(dist,dist+f+1,-1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto next : {curr+u, curr-d})
        {
            if(next > f || next<=0 || dist[next]!= -1)
            {
                continue;
            }
            dist[next] = dist[curr] + 1;
            q.push(next);
        }
    }
    if(dist[g]==-1)
    {
        cout << "use the stairs";
    }
    else
    {
        cout << dist[g];
    }
}
