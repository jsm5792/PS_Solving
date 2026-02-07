#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,M,K;
vector<int> v[200005];
int dist[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K >> M;
    for(int i=1;i<=M;i++)
    {
        for(int j=0;j<K;j++)
        {
            int x;
            cin >> x;
            v[x].push_back(N+i);
            v[N+i].push_back(x);
        }
    }
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        if(curr == N)
        {
            break;
        }
        for(auto next : v[curr])
        {
            if(dist[next]!=0)
            {
                continue;
            }
            dist[next] = dist[curr]+1;
            q.push(next);
        }
    }
    if(dist[N]==0)
    {
        cout << "-1";
    }
    else
    {
        cout << dist[N]/2 + 1;
    }
}
