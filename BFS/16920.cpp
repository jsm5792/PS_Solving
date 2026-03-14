#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N,M,P;
int board[1005][1005];
int step[15];
int area[15];
queue<tuple<int,int,int>> q[15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> P;
    for(int i=1;i<=P;i++)
    {
        cin >> step[i];
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            char c;
            cin >> c;
            if(c=='.')
            {
                board[i][j]=1;
            }
            else if(c=='#')
            {
                board[i][j]=0;
            }
            else
            {
                board[i][j]=0;
                q[c-'0'].push({i,j,0});
                area[c-'0'] ++;
            }
        }
    }
    while(1)
    {
        bool check = false;
        for(int i=1;i<=P;i++)
        {
            queue<tuple<int,int,int>> q1;
            while(!q[i].empty())
            {
                int x,y,z;
                tie(x,y,z) = q[i].front();
                q[i].pop();
                if(z >= step[i])
                {
                    q1.push({x,y,0});
                    continue;
                }
                for(int j=0;j<4;j++)
                {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx<0 || ny<0 || nx>=N || ny>=M)
                    {
                        continue;
                    }
                    if(board[nx][ny]==0)
                    {
                        continue;
                    }
                    q[i].push({nx,ny,z+1});
                    board[nx][ny]=0;
                    area[i]++;
                    check = true;
                }
            }
            q[i] = q1;
        }
        if(check == false)
        {
            break;
        }
    }
    for(int i=1;i<=P;i++)
    {
        cout << area[i] << ' ';
    }
}
