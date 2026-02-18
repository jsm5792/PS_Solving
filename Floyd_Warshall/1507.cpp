#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;

int board[25][25];
bool road[25][25];



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> board[i][j];
        }
        fill(road[i],road[i]+N+1,true);
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(k==i || i==j || j==k)
                {
                    continue;
                }
                if(board[i][j] > board[i][k]+board[k][j])
                {
                    cout<<-1;
                    return 0;
                }
                if(board[i][j]==board[i][k]+board[k][j])
                {
                    road[i][j] = false;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(road[i][j])
            {
                ans += board[i][j];
            }
        }
    }
    ans /= 2;
    cout << ans;

}
