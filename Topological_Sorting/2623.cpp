#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector<int> v[1005];
int indegree[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int x,prev;
        cin >> x;
        for(int j=0;j<x;j++)
        {
            int y;
            cin >> y;
            if(j!=0)
            {
                v[prev].push_back(y);
                indegree[y]++;
            }
            prev = y;
        }
    }
    queue<int> q;
    queue<int> ans;
    for(int i=1;i<=N;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    int count =0;
    while(!q.empty())
    {
        int curr = q.front();
        ans.push(curr);
        q.pop();
        count++;
        for(auto next : v[curr])
        {
            indegree[next]--;
            if(indegree[next]==0)
            {
                q.push(next);
            }
        }
    }
    if(count == N)
    {
        while(!ans.empty())
        {
            cout << ans.front() <<'\n';
            ans.pop();
        }
    }
    else
    {
        cout << '0';
    }

}
