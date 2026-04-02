#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int board[505][505];
int dp[505][505];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int solve(int x,int y)
{
    if(x==N-1 && y==M-1) return 1;
    if(dp[x][y]!=-1) return dp[x][y];

    dp[x][y]=0;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(nx<0||ny<0||nx>=N||ny>=M) continue;
        if(board[nx][ny]<board[x][y])
        {
            dp[x][y]+=solve(nx,ny);
        }
    }
    return dp[x][y];
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
            dp[i][j]=-1;
        }
    }

    cout << solve(0,0);

}
