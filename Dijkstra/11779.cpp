#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,st,en;
vector<pair<int,int>> v[1005];
int a[1005];
int b[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    fill(a,a+N+1,1e9);
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        v[x].push_back({z,y});
    }
    cin >> st >> en;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    a[st] = 0;
    pq.push({a[st],st});
    while(!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        if(a[curr.second] != curr.first)
        {
            continue;
        }
        for(auto next : v[curr.second])
        {
            if(a[next.second] > a[curr.second] + next.first)
            {
                a[next.second] = a[curr.second] + next.first;
                pq.push({a[next.second],next.second});
                b[next.second] = curr.second;
            }
        }
    }
    vector <int> v1;
    int curr = en;
    cout << a[en] << '\n';
    while(curr!=st)
    {
        v1.push_back(curr);
        curr = b[curr];
    }
    v1.push_back(curr);
    cout << v1.size() << '\n';
    for(int i=v1.size()-1;i>=0;i--)
    {
        cout << v1[i] << ' ';
    }
}
