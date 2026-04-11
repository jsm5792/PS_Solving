#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[25][25];
int N;
int ans = 1e9;
int tot = 0;

void solve(int x,int y, int d1, int d2)
{
    int arr[6] ={};
    for(int i=1;i<x+d1;i++)
    {
        for(int j=1;j<=y;j++)
        {
            if(i>=x && j>= y -(i-x))
            {
                continue;
            }
            arr[1] += board[i][j];
        }
    }

    for(int i=1;i<=x+d2;i++)
    {
        for(int j=y+1;j<=N;j++)
        {
            if(i>=x && j<= y+(i-x))
            {
                continue;
            }
            arr[2] += board[i][j];
        }
    }

    for(int i=x+d1;i<=N;i++)
    {
        for(int j=1;j<y-d1+d2;j++)
        {
            if(i<=x+d1+d2 && j >= (y-d1)+(i-(x+d1)))
            {
                continue;
            }
            arr[3] += board[i][j];
        }
    }

    for(int i=x+d2+1;i<=N;i++)
    {
        for(int j=y-d1+d2;j<=N;j++)
        {
            if(i<=x+d1+d2 && j <= (y+d2)-(i-(x+d2)))
            {
                continue;
            }
            arr[4] += board[i][j];
        }
    }

    arr[5] = tot - (arr[1] + arr[2] + arr[3] + arr[4]);
    int mi = arr[1];
    int ma = arr[1];
    for(int i=1;i<=5;i++)
    {
        mi = min(mi,arr[i]);
        ma = max(ma,arr[i]);
    }
    ans = min(ans, ma-mi);
}

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
            tot += board[i][j];
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int d1=1;d1<=N;d1++)
            {
                for(int d2=1;d2<=N;d2++)
                {
                    if(i+d1+d2 > N)
                    {
                        continue;
                    }
                    if(j-d1<1 || j+d2>N)
                    {
                        continue;
                    }
                    solve(i,j,d1,d2);
                }
            }
        }
    }
    cout << ans;
}
