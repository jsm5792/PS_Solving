#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int R,C,T;
int board[55][55];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int block;

void spread()
{
    int board1[55][55] = {};
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            if(board[i][j]==-1)
            {
                board1[i][j] = -1;
                continue;
            }
            if(board[i][j]==0)
            {
                continue;
            }
            int cnt = 0;
            for(int d=0;d<4;d++)
            {
                int x = i + dx[d];
                int y = j + dy[d];
                if(x<1 || y<1 || x>R || y>C)
                {
                    continue;
                }
                if(board[x][y]==-1)
                {
                    continue;
                }
                cnt++;
                board1[x][y] += board[i][j]/5;
            }
            board1[i][j] += board[i][j] - (board[i][j]/5) * cnt;
        }
    }
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            board[i][j] = board1[i][j];
        }
    }
}

void cleaner()
{
    int up = block-1;
    int down = block;
    for(int i=up-1;i>1;i--)
    {
        board[i][1] = board[i-1][1];
    }
    for(int i=1;i<C;i++)
    {
        board[1][i] = board[1][i+1];
    }
    for(int i=1;i<up;i++)
    {
        board[i][C] = board[i+1][C];    
    }
    for(int i=C;i>2;i--)
    {
        board[up][i] = board[up][i-1];
    }
    board[up][2] = 0;
    
    for(int i=down+1;i<R;i++)
    {
        board[i][1] = board[i+1][1];
    }
    for(int i=1;i<C;i++)
    {
        board[R][i] = board[R][i+1];
    }
    for(int i=R;i>down;i--)
    {
        board[i][C] = board[i-1][C];
    }
    for(int i=C;i>2;i--)
    {
        board[down][i] = board[down][i-1];
    }
    board[down][2] = 0;


}

void simulate()
{
    spread();
    cleaner();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> T;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cin >> board[i][j];
            if(board[i][j]==-1)
            {
                block = i;
            }
        }
    }
    while(T--)
    {
        simulate();
    }
    int ans = 0;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            if(board[i][j]!=-1)
            {
                ans += board[i][j];
            }
        }
    }
    cout << ans;
}
