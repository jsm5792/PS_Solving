#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int board[55][55];
int ans;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int r,c,d;
    cin >> r >> c >> d;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >> board[i][j];
        }
    }
    while(1)
    {
        if(board[r][c] == 0)
        {
            board[r][c] = 2;
            ans++;
        }
        int i = 1;
        bool check = false;
        while(i<=4 && check == false)
        {
            d = (d+3) %4;
            int x = r + dx[d];
            int y = c + dy[d];
            if(x <0 || y<0 || x>=N || y>=M)
            {
                i++;
                continue;
            }
            if(board[x][y] == 0)
            {
                check = true;
                r = x;
                c = y;
                break;
            }
            i++;
        }
        if(check == false)
        {
            int x = r - dx[d];
            int y = c - dy[d];
            if(board[x][y]==1 || x <0 || y<0 || x>=N || y>=M)
            {
                cout << ans;
                return 0;
            }
            r = x;
            c = y;
        }
    }
}