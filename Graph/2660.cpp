#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
vector <int> v[55];
int score[55];

void BFS(int x)
{
    int dist[55];
    fill(dist,dist+55,-1);
    queue<int> q;
    dist[x]=0;
    q.push(x);
    int max_dist = 0;
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
            max_dist = max(max_dist,dist[next]);
            q.push(next);
        }
    }
    score[x] = max_dist;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(1)
    {
        int x,y;
        cin >> x >> y;
        if(x==-1 && y==-1)
        {
            break;
        }
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=N;i++)
    {
        BFS(i);
    }
    int min_score = 10000;
    for(int i=1;i<=N;i++)
    {
        min_score = min(min_score, score[i]);        
    }
    queue<int> q1;
    for(int i=1;i<=N;i++)
    {
        if(score[i]==min_score)
        {
            q1.push(i);
        }
    }
    cout << min_score << ' '<< q1.size() <<'\n';
    while(!q1.empty())
    {
        cout << q1.front()<<' ';
        q1.pop();
    }
}
