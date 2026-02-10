#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector <int> v[32005];
int indegree[32005];

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
        indegree[y]++;
    }
    queue<int> q;
    for(int i=1;i<=N;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << ' ';
        for(auto next : v[curr])
        {
            indegree[next]--;
            if(indegree[next]==0)
            {
                q.push(next);
            }
        }
    }
}
