#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<pair<int,int>> v[1005];

vector<int> solve(int st)
{
    vector<int> d(N+1,1e9);
    d[st] = 0;
    priority_queue <pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,st});
    
    while(!pq.empty())
    {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();
        if(d[y] != x)
        {
            continue;
        }
        for(auto next: v[y])
        {
            int dx = next.first;
            int dy = next.second;
            if(d[dy] > x + dx)
            {
                d[dy] = x + dx;
                pq.push({d[dy],dy});
            }
        }
    }
    return d;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
    }
    int v1,v2;
    cin >> v1 >> v2;
    vector<int> ans = solve(v1);
    cout << ans[v2];
}
