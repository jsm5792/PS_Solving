#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int board[105][105];
bool vis[105][105];
vector<pair<int,int>> v[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool check(pair<int,int> p)
{
    for(int i=0;i<4;i++)
    {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];
        if(nx<1 || ny<1 || nx>N || ny>N)
        {
            continue;
        }
        if(vis[nx][ny])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v[a][b].push_back({c,d});
    }
    queue<pair<int,int>> q;
    board[1][1] = 1;
    vis[1][1] = true;
    q.push({1,1});
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(auto next : v[x][y])
        {
            int nx = next.first;
            int ny = next.second;
            if(vis[nx][ny])
            {
                continue;
            }
            board[nx][ny] = 1;
            if(check({nx,ny}))
            {
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<1 || ny<1 || nx>N || ny>N)
            {
                continue;
            }
            if(vis[nx][ny] || board[nx][ny]==0)
            {
                continue;
            }
            vis[nx][ny] = true;
            q.push({nx,ny});
        }
    }
    int ans =0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            ans += board[i][j];
        }
    }
    cout << ans;
}
