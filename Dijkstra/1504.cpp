#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,E;
vector<pair<int,int>> v[805];

vector<int> solve(int st)
{
    vector<int> d(N+1,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[st] = 0;
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
        for(auto next : v[y])
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
    cin >> N >> E;
    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    int v1,v2;
    cin >> v1 >> v2;
    vector<int> ans_st = solve(1);
    vector<int> ans_v1 = solve(v1);
    vector<int> ans_v2 = solve(v2);
    long long p1 = (long long)ans_st[v1] + ans_v1[v2] + ans_v2[N];
    long long p2 = (long long)ans_st[v2] + ans_v2[v1] + ans_v1[N];
    long long ans = min(p1,p2);
    if(ans >= 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
