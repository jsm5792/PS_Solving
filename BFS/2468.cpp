#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,h;
int board[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int vis[105][105];
int ans;

void BFS(int x,int y, int height)
{
    queue<pair<int,int>> q;
    vis[x][y] = 1;
    q.push({x,y});
    while(!q.empty())
    {
        int z,w;
        tie(z,w) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = z + dx[i];
            int ny = w + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N)
            {
                continue;
            }
            if(vis[nx][ny]==0 && board[nx][ny] > height)
            {
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> board[i][j];
            h = max(board[i][j],h);
        }
    }
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<N;j++)
        {
            fill(vis[j],vis[j]+N,0);
        }
        int cnt = 0;
        for(int x=0;x<N;x++)
        {
            for(int y=0;y<N;y++)
            {
                if(board[x][y] > i && vis[x][y]==0)
                {
                    BFS(x,y,i);
                    cnt++;
                }
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans;


}
