#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int V,E;
int board[405][405];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    for(int i=1;i<=V;i++)
    {
        fill(board[i],board[i]+V+1,100000000);
    }
    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        board[a][b] = c;
    }

    for(int k=1;k<=V;k++)
    {
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                board[i][j] = min(board[i][j],board[i][k]+board[k][j]);
            }
        }
    }

    int ans = 200000000;
    for(int i=1;i<=V;i++)
    {
        ans = min(ans,board[i][i]);
    }
    if(ans == 200000000)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
