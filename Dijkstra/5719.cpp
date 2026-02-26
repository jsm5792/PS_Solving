#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,S,D;
int d[505];
vector <pair<int,int>> v[505];
vector <int> parent[505];
bool removed[505][505];

void solve()
{
    fill(d,d+N,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[S] = 0;
    pq.push({0,S});
    while(!pq.empty())
    {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();
        if(d[y] != x)
        {
            continue;
        }
        for(auto next : v[y])
        {
            int dx = next.first;
            int dy = next.second;
            if(removed[y][dy])
            {
                continue;
            }
            if(d[dy] > x + dx)
            {
                d[dy] = x + dx;
                parent[dy].clear();
                parent[dy].push_back(y);
                pq.push({d[dy],dy});
            }
            else if(d[dy] == x +dx)
            {
                parent[dy].push_back(y);
            }
        }
    }
}

void del()
{
    queue<int> q;
    q.push(D);
    bool vis[505] = {false};
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto next : parent[curr])
        {
            removed[next][curr] = true;
            if(vis[next]==false)
            {
                vis[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        cin >> N >> M;
        if(N==0 && M==0)
        {
            break;
        }
        cin >> S >> D;
        for(int i=0;i<N;i++)
        {
            v[i].clear();
            parent[i].clear();
            fill(removed[i],removed[i]+N,false);
        }
        for(int i=0;i<M;i++)
        {
            int x,y,z;
            cin >> x >> y >> z;
            v[x].push_back({z,y});
        }
        solve();
        del();
        solve();
        if(d[D]==1e9)
        {
            cout << "-1\n";
        }
        else
        {
            cout << d[D] <<'\n';
        }
    }

}
