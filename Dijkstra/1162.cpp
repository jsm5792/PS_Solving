#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
vector<pair<int,int>> v[10005];
long long d[10005][22];

void solve()
{
    for(int i=1;i<=N;i++)
    {
        fill(d[i],d[i]+K+1,1e18);
    }
    priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> pq;
    d[1][0] = 0;
    pq.push({0,1,0});
    while(!pq.empty())
    {
        long long x;
        int y,z;
        tie(x,y,z) = pq.top();
        pq.pop();
        if(d[y][z] != x)
        {
            continue;
        }
        for(auto next : v[y])
        {
            int price = next.first;
            int node = next.second;
            if(d[node][z] > x + price)
            {
                d[node][z] = x + price;
                pq.push({d[node][z],node,z});
            }
            if(z<K && d[node][z+1] > x)
            {
                d[node][z+1] = x;
                pq.push({d[node][z+1],node,z+1});
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].push_back({z,y});
        v[y].push_back({z,x});
    }
    solve();
    long long ans = 1e18;
    for(int i=0;i<=K;i++)
    {
        ans = min(ans, d[N][i]);
    }
    cout << ans;
}
