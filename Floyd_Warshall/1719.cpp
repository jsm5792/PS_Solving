#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;

int board[205][205];
int nxt[205][205];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        fill(board[i],board[i]+N+1,100000);
        board[i][i] = 0;
    }
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        board[a][b] = c;
        board[b][a] = c;
        nxt[a][b] = b;
        nxt[b][a] = a;
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(board[i][j] > board[i][k]+board[k][j])
                {
                    board[i][j] = board[i][k]+board[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i==j)
            {
                cout << "- ";
            }
            else
            {
                cout << nxt[i][j] <<' ';
            }
        }
        cout <<'\n';
    }
}
