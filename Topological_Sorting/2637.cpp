#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int indegree[105];
int cost[105][105];
vector<pair<int,int>> v[105];
bool basic[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    queue<int> q;
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        v[y].push_back({x,z});
        indegree[x]++;
    }
    for(int i=1;i<=N;i++)
    {
        if(indegree[i]==0)
        {
            cost[i][i] = 1;
            basic[i] = true;
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto next : v[curr])
        {
            for(int i=1;i<=N;i++)
            {
                if(basic[i])
                {
                    cost[next.first][i] += cost[curr][i] * next.second;
                }
            }
            indegree[next.first]--;
            if(indegree[next.first]==0)
            {
                q.push(next.first);
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(basic[i])
        {
            cout << i << " "<<cost[N][i]<<'\n';
        }
    }

}
