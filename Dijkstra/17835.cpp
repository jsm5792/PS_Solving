#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;

vector<pair<int,int>> v[100005];
long long d[100005];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    fill(d,d+N+1,1e15);
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[b].push_back({c,a});
    }
    priority_queue <pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    for(int i=0;i<K;i++)
    {
        int x;
        cin >> x;
        d[x] = 0;
        pq.push({0,x});
    }
    while(!pq.empty())
    {
        long long x = pq.top().first;
        int y = pq.top().second;
        pq.pop();
        if(d[y] != x)
        {
            continue;
        }
        for(auto next : v[y])
        {
            long long dx = next.first;
            int dy = next.second;
            if(d[dy] > x + dx)
            {
                d[dy] = x + dx;
                pq.push({d[dy],dy});
            }
        }
    }
    int city =0;
    long long dist = -1;
    for(int i=1;i<=N;i++)
    {
        if(d[i] > dist)
        {
            dist = d[i];
            city = i;
        }
    }
    cout << city <<'\n' << dist;


}
