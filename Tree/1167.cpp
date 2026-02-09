#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,max_d,node;
vector<pair<int,int>> v[100005];
bool vis[100005];

void DFS(int curr,int dist)
{
    vis[curr] = true;
    if(dist > max_d)
    {
        max_d = dist;
        node = curr;
    }
    for(auto next: v[curr])
    {
        if(vis[next.first])
        {
            continue;
        }
        DFS(next.first,dist + next.second);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int x;
        cin >> x;
        while(1)
        {
            int y,z;
            cin >> y;
            if(y==-1)
            {
                break;
            }
            cin >> z;
            v[x].push_back({y,z});
        } 
    }
    DFS(1,0);
    fill(vis,vis+N+1,false);
    max_d = 0;
    DFS(node,0);
    cout << max_d;

}
