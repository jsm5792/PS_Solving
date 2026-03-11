#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char board[35][35][35];
int vis[35][35][35];
int L,R,C;
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        queue<tuple<int,int,int>> q;
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0)
        {
            break;
        }
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<R;j++)
            {
                string s;
                cin >> s;
                for(int k=0;k<C;k++)
                {
                    board[i][j][k] = s[k];
                    vis[i][j][k] = -1;
                    if(board[i][j][k]=='S')
                    {
                        vis[i][j][k] = 0;
                        q.push({i,j,k});
                    }
                }
            }
        }
        bool check = false;

        while(!q.empty())
        {
            int x,y,z;
            tie(x,y,z) = q.front();
            q.pop();
            for(int i=0;i<6;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if(nx<0 || ny<0 || nz<0 || nx>=L || ny>=R || nz >=C)
                {
                    continue;
                }
                if(vis[nx][ny][nz]!=-1 || board[nx][ny][nz]=='#')
                {
                    continue;
                }
                vis[nx][ny][nz] = vis[x][y][z] + 1;
                if(board[nx][ny][nz]=='E')
                {
                    cout << "Escaped in " << vis[nx][ny][nz] << " minute(s)."<<'\n';
                    check = true;
                    break;
                }
                q.push({nx,ny,nz});
            }
        }
        if(!check)
        {
            cout << "Trapped!"<<'\n';
        }
    }
}
