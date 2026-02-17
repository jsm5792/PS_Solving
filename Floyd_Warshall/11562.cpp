#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int board[255][255];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    for(int i=1;i<=N;i++)
    {
        fill(board[i],board[i]+N+1,50000);
        board[i][i] = 0;
    }
    for(int i=0;i<M;i++)
    {
        int u,v,b;
        cin >> u >> v >> b;
        if(b==1)
        {
            board[u][v] = 0;
            board[v][u] = 0;
        }
        else
        {
            board[u][v] = 0;
            board[v][u] = 1;
        }
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                board[i][j] = min(board[i][j],board[i][k]+board[k][j]);
            }
        }
    }
    cin >> K;
    while(K--)
    {
        int u,v;
        cin >> u >> v;
        cout << board[u][v] <<'\n';
    }

}
