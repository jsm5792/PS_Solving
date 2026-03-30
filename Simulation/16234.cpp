#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,L,R;
int board[55][55];
int ans;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool solve()
{
    bool vis[N][N];
    for(int i=0;i<N;i++)
    {
        fill(vis[i],vis[i]+N,false);
    }
    int count = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(!vis[i][j])
            {
                count ++;
                int curr_sum = 0;
                int curr_num = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                stack<pair<int,int>> s;
                s.push({i,j});
                vis[i][j] = true;
                while(!q.empty())
                {
                    int x,y;
                    tie(x,y) = q.front();
                    q.pop();
                    curr_sum += board[x][y];
                    curr_num ++;
                    for(int d=0;d<4;d++)
                    {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx<0 || ny<0 || nx>=N || ny>=N)
                        {
                            continue;
                        }
                        if(vis[nx][ny])
                        {
                            continue;
                        }
                        if(abs(board[nx][ny]-board[x][y]) > R || abs(board[nx][ny]-board[x][y]) < L)
                        {
                            continue;
                        }
                        q.push({nx,ny});
                        s.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
                int value = curr_sum / curr_num;
                while(!s.empty())
                {
                    int x,y;
                    tie(x,y) = s.top();
                    s.pop();
                    board[x][y] = value;
                }
            }
        }
    }
    if(count == N * N)
    {
        return false;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> L >> R;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> board[i][j];
        }
    }
    while(solve())
    {
        ans++;
    }
    cout << ans;
}
