#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector <int> v[20005];
int dist[20005];
int max_dist;

void BFS()
{
    fill(dist,dist+N+1,-1);
    dist[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto next : v[curr])
        {
            if(dist[next]!=-1)
            {
                continue;
            }
            dist[next] = dist[curr]+1;
            max_dist = max(max_dist, dist[next]);
            q.push(next);
        }
    }
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
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BFS();
    int count = 0;
    for(int i=1;i<=N;i++)
    {
        if(dist[i]==max_dist)
        {
            if(count==0)
            {
                cout << i << ' ' << dist[i]<<' ';
            }
            count ++;
        }
    }
    cout << count;
}
