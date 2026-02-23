#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,X;
vector <pair<int,int>> v[1005];
vector <pair<int,int>> rev[1005];

vector <int> solve(int st,vector<pair<int,int>> a[])
{
    vector<int> d(N+1,1e9);
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
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
        for(auto next : a[y])
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
    cin >> N >> M >> X;
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b});
        rev[b].push_back({c,a});
    }
    vector<int> ans1 = solve(X,v);
    vector<int> ans2 = solve(X,rev);
    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        ans = max(ans, ans1[i] + ans2[i]);
    }
    cout << ans;

}
