#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector <int> v[105];
int score[105];

void BFS(int x)
{
    int dist[105];
    fill(dist,dist+105,-1);
    queue<int> q;
    dist[x] = 0;
    q.push(x);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto next : v[curr])
        {
            if(dist[next]!=-1)
            {
                continue;
            }
            dist[next] = dist[curr]+1;
            q.push(next);
        }
    }
    int temp = 0;
    for(int i=1;i<=N;i++)
    {
        temp += dist[i];
    }
    score[x] = temp;
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
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=N;i++)
    {
        BFS(i);
    }
    int min_score = 10000;
    int min_index = -1;
    for(int i=1;i<=N;i++)
    {
        if(min_score > score[i])
        {
            min_index = i;
            min_score = score[i];
        }
    }
    cout << min_index;
}
