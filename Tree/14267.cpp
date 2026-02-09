#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> v[100005];
int ans[100005];
int a[100005];
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
        vis[next] = true;
        ans[next] = a[next] + ans[curr];
        DFS(next);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        int x;
        cin >> x;
        if(x!=-1)
        {
            v[x].push_back(i);
        }
    }
    for(int i=0;i<M;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x] +=y;
    }
    DFS(1);
    for(int i=1;i<=N;i++)
    {
        cout << ans[i] << ' ';
    }
}
