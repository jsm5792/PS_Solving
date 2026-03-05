#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[10][10];
int tiles[5] = {5,5,5,5,5};
int one_count;
int ans = 30;

bool attach(int size,int x, int y)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(x+i >=10 || y+j>=10 || board[x+i][y+j]==0)
            {
                return false;
            }
        }
    }
    return true;
}

void fix(int size,int x, int y, int tar)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            board[x+i][y+j] = tar;
        }
    }
}

void solve(int cnt, int x, int y)
{
    if(cnt >= ans)
    {
        return;
    }
    if(one_count == 0)
    {
        ans = min(ans, cnt);
        return;
    }
    if(y==10)
    {
        solve(cnt,x+1,0);
        return;
    }
    if(x==10)
    {
        return;
    }
    if(!board[x][y])
    {
        solve(cnt,x,y+1);
        return;
    }
    for(int i=5;i>=1;i--)
    {
        if(tiles[i-1]>0 && attach(i,x,y))
        {
            one_count -= i*i;
            fix(i,x,y,0);
            tiles[i-1]--;
            solve(cnt+1,x,y+1);
            one_count += i*i;
            tiles[i-1]++;
            fix(i,x,y,1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin >> board[i][j];
            if(board[i][j])
            {
                one_count++;
            }
        }
    }
    solve(0,0,0);

    if(ans == 30)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
