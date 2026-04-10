#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[55][55];
int vis[55][55];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int>> virus;
vector<int> v;
int N,M,empty_cnt;
int ans = 1e9;

int BFS()
{
    for(int i=0;i<N;i++)
    {
        fill(vis[i],vis[i]+N+1,-1);
    }
    queue<pair<int,int>> q;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==0)
        {
            continue;
        }
        q.push({virus[i].first,virus[i].second});
        vis[virus[i].first][virus[i].second] = 0;
    }
    int curr_time = 0;
    int cnt = 0;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=N)
            {
                continue;
            }
            if(board[nx][ny]==1 || vis[nx][ny] != -1)
            {
                continue;
            }
            q.push({nx,ny});
            vis[nx][ny] = vis[x][y] + 1;
            if(board[nx][ny]==0)
            {
                cnt++;
                curr_time = max(curr_time,vis[nx][ny]);
            }
        }

    }
    if(cnt == empty_cnt)
    {
        return curr_time;
    }
    return 1e9;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> board[i][j];
            if(board[i][j]==2)
            {
                virus.push_back({i,j});
            }
            if(board[i][j]==0)
            {
                empty_cnt++;
            }
        }
    }
    for(int i=0;i<virus.size()-M;i++)
    {
        v.push_back(0);
    }
    for(int i=0;i<M;i++)
    {
        v.push_back(1);
    }
    do
    {
        ans = min(ans,BFS());
    } while (next_permutation(v.begin(),v.end()));
    if(ans == 1e9)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    

}
