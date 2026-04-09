#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,ans;
int board[505][505];
int dp[505][505];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int solve(int x,int y)
{
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    
    dp[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 || nx>=N || ny>=N)
        {
            continue;
        }
        if(board[nx][ny]>board[x][y])
        {
            dp[x][y]=max(dp[x][y],solve(nx,ny)+1);
        }
    }
    return dp[x][y];
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
            dp[i][j]=-1;
        }
    }
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            ans=max(ans,solve(i,j));
        }
    }
    
    cout << ans;
}
