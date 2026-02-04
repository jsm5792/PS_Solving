#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,st;
vector <int> a[1005];
bool b[1005];


void DFS()
{
    stack<int> s;
    s.push(st);
    while(!s.empty())
    {
        int curr = s.top();
        s.pop();
        if(b[curr])
        {
            continue;
        }
        b[curr] = true;
        cout << curr << ' ';
        for(int i=0;i<a[curr].size();i++)
        {
            int next = a[curr][a[curr].size()-1-i];
            if(b[next])
            {
                continue;
            }
            s.push(next);
        }
    }
}

void BFS()
{
    queue<int> q;
    q.push(st);
    b[st] = true;
    while(!q.empty())
    {
        int curr = q.front();
        cout << curr << ' ';
        q.pop();
        for(auto next : a[curr])
        {
            if(b[next])
            {
                continue;
            }
            q.push(next);
            b[next] = true;
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> st;
    while(M--)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=N;i++)
    {
        sort(a[i].begin(),a[i].end());
    }
    DFS();
    cout << '\n';
    fill(b+1,b+N+1,false);
    BFS();
}
