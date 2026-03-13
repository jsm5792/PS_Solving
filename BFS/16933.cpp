#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string board[1005];
int visit[1005][1005][15][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
    {
        cin >> board[i];
    }
    queue<tuple<int,int,int,int>> q;
    q.push({0,0,0,0});
    visit[0][0][0][0] = 1;
    while(!q.empty())
    {
        int x,y,z,w;
        tie(x,y,z,w) = q.front();
        q.pop();
        if(x==N-1 && y==M-1)
        {
            cout << visit[x][y][z][w];
            return 0;
        }
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny <0 || nx >= N || ny >= M)
            {
                continue;
            }
            if(board[nx][ny]=='0')
            {
                int nz = z;
                int nw = 1-w;
                if(visit[nx][ny][nz][nw] > 0)
                {
                    continue;
                }
                visit[nx][ny][nz][nw] = visit[x][y][z][w] + 1;
                q.push({nx,ny,nz,nw});
            }
            else
            {
                if(z == K)
                {
                    continue;
                }
                if(w == 0)
                {
                    int nz = z+1;
                    int nw = 1-w;
                    if(visit[nx][ny][nz][nw] > 0)
                    {
                        continue;
                    }
                    visit[nx][ny][nz][nw] = visit[x][y][z][w] + 1;
                    q.push({nx,ny,nz,nw});
                }
                else
                {
                    int nw = 0;
                    if(visit[x][y][z][nw] > 0)
                    {
                        continue;
                    }
                    visit[x][y][z][nw] = visit[x][y][z][w] + 1;
                    q.push({x,y,z,nw});
                }
            }
        }
    }
    cout << -1;

}
