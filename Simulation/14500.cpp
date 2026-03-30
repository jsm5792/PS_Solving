#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[505][505];
bool vis[505][505];
int N,M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans;
int sum;

void solve(int x,int y,int cnt)
{
    if(cnt == 4)
    {
        ans = max(ans,sum);
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <0 || ny <0 || nx>= N || ny>=M)
        {
            continue;
        }
        if(vis[nx][ny])
        {
            continue;
        }
        sum += board[nx][ny];
        vis[nx][ny] = true;
        solve(nx,ny,cnt+1);
        if(cnt == 2)
        {
            solve(x,y,cnt+1);
        }
        sum -= board[nx][ny];
        vis[nx][ny] = false;
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            sum = board[i][j];
            vis[i][j] = true;
            solve(i,j,1);
            vis[i][j] = false;
        }
    }
    cout << ans;
}
