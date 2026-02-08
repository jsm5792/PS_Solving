#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,R,Q,ans;
vector <int> v[100005];
int size[100005];
bool vis[100005];

int DFS(int curr)
{
    vis[curr] = true;
    size[curr] = 1;
    for(auto next : v[curr])
    {
        if(vis[next
        ])
        {
            continue;
        }
        size[curr] += DFS(next);
    }
    return size[curr];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> R >> Q;
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(R);
    for(int i=0;i<Q;i++)
    {
        int x;
        cin >> x;
        cout << size[x] <<'\n';
    }

}
