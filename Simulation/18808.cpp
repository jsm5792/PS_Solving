#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int board[45][45];
int paper[15][15];
int r,c;

void rotate()
{
    int temp[12][12];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            temp[i][j] = paper[i][j];
        }
    }
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            paper[i][j] = temp[r-1-j][i];
        }
    }
    swap(r,c);
}

bool check(int x,int y)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(board[x+i][y+j] == 1 && paper[i][j] == 1)
            {
                return false;
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(paper[i][j]==1)
            {
                board[x+i][y+j] = 1;
            }
        }
    }
    return true;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int k=0;k<K;k++)
    {
        cin >> r >> c;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin >> paper[i][j];
            }
        }
        for(int d=0;d<4;d++)
        {
            bool ok = false;
            for(int x=0;x<= N-r;x++)
            {
                if(ok)
                {
                    break;
                }
                for(int y=0;y<= M-c;y++)
                {
                    if(check(x,y))
                    {
                        ok = true;
                        break;
                    }
                }
            }
            if(ok)
            {
                break;
            }
            rotate();
        }
    }
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            ans += board[i][j];
        }
    }
    cout << ans;
}
