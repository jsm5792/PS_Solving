#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int board[105][105];
bool visit[105][105];
vector<int> v;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> K;
    queue <pair<int,int>> q;
    for(int i=0;i<K;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        for(int j=a;j<c;j++)
        {
            for(int k=b;k<d;k++)
            {
                board[k][j] = 1;
            }
        }
    }
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j]==1 || visit[i][j])
            {
                continue;
            }
            int area = 0;
            visit[i][j] = true;
            q.push({i,j});
            while(!q.empty())
            {
                int x,y;
                tie(x,y) = q.front();
                q.pop();
                area++;
                for(int d=0;d<4;d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx < 0 || ny <0 || nx >= M || ny >= N)
                    {
                        continue;
                    }
                    if(visit[nx][ny] || board[nx][ny]==1)
                    {
                        continue;
                    }
                    visit[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
            v.push_back(area);
        }
    }
    sort(v.begin(),v.end());
    cout << v.size()<<'\n';
    for(auto i : v)
    {
        cout << i << ' ';
    }
}
