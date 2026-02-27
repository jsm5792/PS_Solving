#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K,S,D;
long long d[1005][1005];
vector <pair<int,int>> v[1005];

void solve()
{
    for(int i=0;i<=N;i++)
    {
        fill(d[i],d[i]+N+1,1e15);
    }
    priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> pq;
    d[S][0] = 0;
    pq.push({0, S,0});
    while(!pq.empty())
    {
        long long dist;
        int curr, cnt;
        tie(dist,curr,cnt) = pq.top();
        pq.pop();

        if(d[curr][cnt] < dist)
        {
            continue;
        }
        for(auto next : v[curr])
        {
            int weight = next.first;
            int nxt_node = next.second;
            if(d[nxt_node][cnt+1] > dist + weight)
            {
                d[nxt_node][cnt+1] = dist + weight;
                pq.push({d[nxt_node][cnt+1], nxt_node,cnt+1});
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K >> S >> D;
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].push_back({z,y});
        v[y].push_back({z,x});
    }
    solve();
    long long min_d = 1e15;
    for(int i=1;i<N;i++)
    {
        min_d = min(min_d,d[D][i]);
    }
    cout << min_d <<'\n';
    
    long long total = 0;
    for(int i=0;i<K;i++)
    {
        int x;
        cin >> x;
        total += x;
        min_d = 1e15;
        for(int j=1;j<N;j++)
        {
            if(d[D][j]==1e15)
            {
                continue;
            }
            min_d = min(min_d,d[D][j]+(long long) j*total);
        }
        cout << min_d <<'\n';
    }
}
