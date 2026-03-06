#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int board[1005][1005];
int dist[1005][1005][15];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin >> s;
        for(int j=1;j<=M;j++)
        {
            board[i][j] = s[j-1] - '0';
            for(int k=0;k<=K;k++)
            {
                dist[i][j][k] = -1;
            }
        }
    }
    queue <tuple<int,int,int>> q;
    q.push({1,1,0});
    dist[1][1][0] = 1;

    while(!q.empty())
    {
        int x,y,k;
        tie(x,y,k) = q.front();
        q.pop();
        if(x == N && y == M)
        {
            break;
        }
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <=0 || ny<=0 || nx> N || ny>M)
            {
                continue;
            }
            if(board[nx][ny]==1)
            {
                if(k == K)
                {
                    continue;
                }
                if(dist[nx][ny][k+1] != -1)
                {
                    continue;
                }
                dist[nx][ny][k+1] = dist[x][y][k] + 1;
                q.push({nx,ny,k+1});

            }
            else
            {
                if(dist[nx][ny][k] != -1)
                {
                    continue;
                }
                dist[nx][ny][k] = dist[x][y][k] + 1;
                q.push({nx,ny,k});
            }
        }
        
    }


    int ans = 1e8;
    for(int i=0;i<=K;i++)
    {
        if(dist[N][M][i]==-1)
        {
            continue;
        }
        ans = min(ans, dist[N][M][i]);
    }
    if(ans == 1e8)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
