#include <iostream>
#include <vector>

using namespace std;

int N,M,H;
bool board[31][11];
int ans = 4;

bool check()
{
    int a[10];
    for(int i=0;i<N;i++)
    {
        a[i]=i;
    }
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            if(board[i][j])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        if(a[i]!=i)
        {
            return false;
        }
    }
    return true;
}

void dfs(int count, int x, int y)
{
    if(count >= ans)
    {
        return;
    }
    if(check())
    {
        ans = min(ans,count);
        return;
    }
    if(count == 3)
    {
        return;
    }
    for(int i=x;i<H;i++)
    {
        int start_y;
        if(i==x)
        {
            start_y = y;
        }
        else
        {
            start_y = 0;
        }
        for(int j=start_y;j<N;j++)
        {
            if(board[i][j] || board[i][j-1] || board[i][j+1])
            {
                continue;
            }
            board[i][j] = true;
            dfs(count+1,i,j+2);
            board[i][j] = false;
        }
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;
    for(int i=0;i<M;i++)
    {
        int x,y;
        cin >> x >> y;
        board[x-1][y-1] = true;
    }
    dfs(0,0,0);
    if(ans<=3)
    {
        cout << ans;
    }
    else
    {
        cout << -1;
    }
}