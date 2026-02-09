#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> v[100005];
bool vis[100005];

void DFS(int curr)
{
    vis[curr] = true;
    for(auto next : v[curr])
    {
        if(vis[next])
        {
            continue;
        }
        DFS(next);
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
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int count =0;
    for(int i=1;i<=N;i++)
    {
        if(vis[i])
        {
            continue;
        }
        count ++;
        DFS(i);
    }
    cout << M-N+2*count-1;
}
