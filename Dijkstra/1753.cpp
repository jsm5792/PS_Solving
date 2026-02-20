#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int V,E,K;
vector<pair<int,int>> v1[20005];
int a[20005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E >> K;
    fill(a,a+V+1,1e9);
    for(int i=0;i<E;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        v1[u].push_back({w,v});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    a[K]=0;
    pq.push({a[K],K});
    while(!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        if(a[curr.second] != curr.first)
        {
            continue;
        }
        for(auto next : v1[curr.second])
        {
            if(a[next.second] <= a[curr.second] + next.first)
            {
                continue;
            }
            a[next.second] = a[curr.second] + next.first;
            pq.push({a[next.second],next.second});
        }
    }
    for(int i=1;i<=V;i++)
    {
        if(a[i]==1e9)
        {
            cout << "INF\n";
        }
        else
        {
            cout << a[i] << '\n';
        }
    }
}

