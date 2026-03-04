#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,G,R;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[51][51];
vector <pair<int,int>> v;
int ans;

int solve(vector <int>& p)
{
    int dist[51][51];
    int color[51][51];
    for(int i=0;i<N;i++)
    {
        fill(dist[i],dist[i]+M,-1);
        fill(color[i],color[i]+M,0);
    }
    queue<pair<int,int>> q;
    int temp = 0;
    for(int i=0;i<v.size();i++)
    {
        if(p[i]==0)
        {
            continue;
        }
        int x = v[i].first;
        int y = v[i].second;
        dist[x][y] = 0;
        color[x][y] = p[i];
        q.push({x,y});
    }
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(color[x][y] == 5)
        {
            continue;
        }
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny <0 || ny >= M)
            {
                continue;
            }
            if(board[nx][ny]==0 || color[nx][ny]==5)
            {
                continue;
            }
            if(color[nx][ny]==0)
            {
                dist[nx][ny] = dist[x][y] + 1;
                color[nx][ny] = color[x][y];
                q.push({nx,ny});
            }
            else if(color[nx][ny] != color[x][y])
            {
                if(dist[nx][ny] == dist[x][y] + 1)
                {
                    color[nx][ny] = 5;
                    temp++;
                }
            }
        }
    }
    return temp;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> G >> R;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> board[i][j];
            if(board[i][j]==2)
            {
                v.push_back({i,j});
            }
        }
    }
    vector<int> p(v.size(),0);
    for(int i=v.size()-G-R;i<v.size()-R;i++)
    {
        p[i] = 1;
    }
    for(int i=v.size()-R;i<v.size();i++)
    {
        p[i] = 2;
    }
    do
    {
        ans = max(ans, solve(p));
    } while (next_permutation(p.begin(),p.end()));

    cout << ans;
    
}
