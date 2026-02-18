#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,T;

int board[305][305];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> T;
    for(int i=1;i<=N;i++)
    {
        fill(board[i],board[i]+N+1,100000000);
        board[i][i] = 0;
    }
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        board[a][b] = c;
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                board[i][j] = min(board[i][j],max(board[i][k],board[k][j]));
            }
        }
    }
    for(int i=0;i<T;i++)
    {
        int x,y;
        cin >> x >> y;
        if(board[x][y]==100000000)
        {
            cout << "-1\n";
        }
        else
        {
            cout << board[x][y]<<'\n';
        }
    }
}
