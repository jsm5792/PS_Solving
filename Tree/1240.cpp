#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<pair<int,int>> v[1005];
bool vis[1005];


int DFS(int x,int y)
{
    if(x==y)
    {
        return 0;
    }
    vis[x] = true;
    for(auto& edge: v[x])
    {
        int next = edge.first;
        int dist = edge.second;
        if(vis[next])
        {
            continue;
        }
        int res = DFS(next,y);
        if(res!=-1)
        {
            return res + dist;
        }
    }
    return -1;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N-1;i++)
    {
        int x,y,d;
        cin >> x >> y >> d;
        v[x].push_back({y,d});
        v[y].push_back({x,d});
    }
    for(int i=0;i<M;i++)
    {
        fill(vis,vis+N+1,false);
        int x,y;
        cin >> x >> y;
        cout << DFS(x,y) <<'\n';
    }
}
