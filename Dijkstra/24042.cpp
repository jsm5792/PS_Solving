#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
long long d[100005];
vector<pair<int,int>> v[100005];

void solve()
{
    priority_queue <pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    d[1] = 0;
    pq.push({0,1});
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
            int index = next.first;
            int target = next.second;
            long long wait = (index - (x % M) + M) % M;
            long long next_t = x + wait + 1;
            if(d[target] > next_t)
            {
                d[target] = next_t;
                pq.push({next_t, target});
            }

        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back({i,y});
        v[y].push_back({i,x});
    }
    fill(d,d+N+1,1e15);
    solve();
    cout << d[N];

}
