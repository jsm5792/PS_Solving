#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
vector <pair<int,int>> v[1005];
priority_queue<int> d[1005];

void solve()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[1].push(0);
    pq.push({0,1});
    while(!pq.empty())
    {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();
        for(auto next : v[y])
        {
            int dx = next.first;
            int dy = next.second;
            if(d[dy].size() < K)
            {
                d[dy].push(x+dx);
                pq.push({x+dx,dy});
            }
            else if(d[dy].top() > x + dx)
            {
                d[dy].pop();
                d[dy].push(x+dx);
                pq.push({x+dx,dy});
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
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
    }
    solve();
    for(int i=1;i<=N;i++)
    {
        if(d[i].size() < K)
        {
            cout << "-1\n";
        }
        else
        {
            cout << d[i].top() <<'\n';
        }
    }
}
