#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int board[205][205];
tuple<int,int,int> edge[20005];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        fill(board[i],board[i]+N+1,1000000);
        board[i][i] = 0;
    }
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        board[a][b] = min(c, board[a][b]);
        board[b][a] = min(c, board[b][a]);
        edge[i] = {a,b,c};
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
    double ans = 1000000;
    for(int i=1;i<=N;i++)
    {
        double curr = 0;
        for(int j=0;j<M;j++)
        {
            int a,b,c;
            tie(a,b,c) = edge[j];
            curr = max(curr, (double)(c+board[i][a]+board[i][b])/2);
        }
        ans = min(curr, ans);
    }
    cout << fixed;
    cout.precision(1);
    cout << ans;
}
