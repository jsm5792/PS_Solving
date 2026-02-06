#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,T;
vector<int> v[20005];
int dist[20005];

bool BFS(int x)
{
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto next : v[curr])
        {
            if(dist[next]==dist[curr])
            {
                return false;
            }
            if(dist[next]!=-1)
            {
                continue;
            }
            dist[next]=(dist[curr]+1)%2;
            q.push(next);
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> N >> M;
        while(M--)
        {
            int x,y;
            cin >> x >>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        fill(dist,dist+N+1,-1);
        bool result = true;
        for(int i=1;i<=N;i++)
        {
            if(dist[i]==-1)
            {
                if(!BFS(i))
                {
                    result = false;
                    break;
                }
            }
        }
        if(result)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

        for(int i=1;i<=N;i++)
        {
            v[i].clear();
        }
    }
}
