#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, Q;
int board[305][305][305];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> board[0][i][j];
            if(i!=j && board[0][i][j]==0)
            {
                board[0][i][j] = 170325;
            }
        }
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                board[k][i][j] = min(board[k-1][i][j],board[k-1][i][k]+board[k-1][k][j]);
            }
        }
    }
    while(Q--)
    {
        int C,s,e;
        cin >> C >> s >> e;
        if(board[C-1][s][e]==170325)
        {
            cout << "-1\n";
        }
        else
        {
            cout << board[C-1][s][e]<<'\n';
        }
    }
}
