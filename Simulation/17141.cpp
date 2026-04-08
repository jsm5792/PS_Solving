#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,empty_cnt;
int ans=1e9;
int board[55][55];
int dist[55][55];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
vector<pair<int,int>> virus_pos;
vector<int> pick;

void bfs()
{
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++)
    {
        fill(dist[i],dist[i]+N,-1);
    }
    int infected=0,max_dist=0;
    for(int i=0;i<pick.size();i++)
    {
        int x=virus_pos[pick[i]].first;
        int y=virus_pos[pick[i]].second;
        dist[x][y]=0;
        q.push({x,y});
        infected++;
    }
    while(!q.empty())
    {
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];
            if(nx<0||ny<0||nx>=N||ny>=N)
            {
                continue;
            }
            if(board[nx][ny]!=1&&dist[nx][ny]==-1)
            {
                dist[nx][ny]=dist[cur.first][cur.second]+1;
                max_dist=max(max_dist,dist[nx][ny]);
                infected++;
                q.push({nx,ny});
            }
        }
    }
    if(infected==empty_cnt)
    {
        ans=min(ans,max_dist);
    }
}

void solve(int idx,int cnt)
{
    if(cnt==M)
    {
        bfs();
        return;
    }
    for(int i=idx;i<virus_pos.size();i++)
    {
        pick.push_back(i);
        solve(i+1,cnt+1);
        
        pick.pop_back();
    }
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
            if(board[i][j]!=1)
            {
                empty_cnt++;
            }
            if(board[i][j]==2)
            {
                virus_pos.push_back({i,j});
            }
        }
    }
    solve(0,0);
    if(ans==1e9)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
