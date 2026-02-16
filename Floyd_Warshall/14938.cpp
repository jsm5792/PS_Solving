#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,R;
int board[105][105];
int nxt[105][105];
int item[105];
bool vis[105];

void visit(int x,int y)
{
    int curr = x;
    while(curr!=y)
    {
        vis[curr] = true;
        curr = nxt[curr][y];
    }
    vis[y] = true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> R;
    for(int i=1;i<=N;i++)
    {
        cin >> item[i];
    }
    for(int i=1;i<=N;i++)
    {
        fill(board[i],board[i]+N+1,1000);
        board[i][i] = 0;
    }
    for(int i=0;i<R;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b],c);
        board[b][a] = min(board[b][a],c);
        nxt[a][b] = b;
        nxt[b][a] = a;
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(board[i][j]>board[i][k]+board[k][j])
                {
                    board[i][j] = board[i][k] + board[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        int temp = 0;
        fill(vis,vis+N+1,false);
        for(int j=1;j<=N;j++)
        {
            if(board[i][j] > M)
            {
                continue;
            }
            visit(i,j);
        }
        for(int j=1;j<=N;j++)
        {
            if(vis[j])
            {
                temp += item[j];
            }
        }
        ans = max(ans, temp);
    }
    cout << ans;
}
