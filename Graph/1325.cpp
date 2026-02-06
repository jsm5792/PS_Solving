#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,M;
vector<int> v[10005];
int a[10005];
bool dist[10005];

void BFS(int x)
{
    fill(dist,dist+N+1,false);
    queue<int> q;
    dist[x] = true;
    q.push(x);
    int count = 0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto next : v[curr])
        {
            if(dist[next])
            {
                continue;
            }
            dist[next] = true;
            count++;
            q.push(next);
        }
    }
    a[x] = count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while(M--)
    {
        int x,y;
        cin >> x >> y;
        v[y].push_back(x);
    }
    for(int i=1;i<=N;i++)
    {
        BFS(i);
    }
    int max_count = 0;
    for(int i=1;i<=N;i++)
    {
        max_count = max(max_count,a[i]);
    }
    for(int i=1;i<=N;i++)
    {
        if(max_count == a[i])
        {
            cout << i << ' ';
        }
    }

}
