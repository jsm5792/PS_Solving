#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T,H,W;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char board[105][105];
int vis[105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> H >> W;
        queue<pair<int,int>> q;
        queue<pair<int,int>> door[26];
        int key[26] = {};
        int count =0;
        for(int i=0;i<=H+1;i++)
        {
            fill(vis[i],vis[i]+W+2,0);
            fill(board[i],board[i]+W+2,0);
        }
        for(int i=1;i<=H;i++)
        {
            for(int j=1;j<=W;j++)
            {
                cin >> board[i][j];
            }
        }
        string s;
        cin >> s;
        for(auto i : s)
        {
            key[i-'a'] = 1;
        }
        q.push({0,0});
        vis[0][0] = 1;
        while(!q.empty())
        {
            int x,y;
            tie(x,y) = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || ny<0 || nx > H+1 || ny > W+1)
                {
                    continue;
                }
                if(vis[nx][ny] || board[nx][ny]=='*')
                {
                    continue;
                }
                vis[nx][ny] = 1;
                if(board[nx][ny] >= 'a' && board[nx][ny] <= 'z')
                {
                    int temp = board[nx][ny] - 'a';
                    key[temp] = 1;
                    while(!door[temp].empty())
                    {
                        int n1,n2;
                        tie(n1,n2) = door[temp].front();
                        door[temp].pop();
                        q.push({n1,n2});
                    }
                }
                else if(board[nx][ny] >= 'A' && board[nx][ny] <= 'Z')
                {
                    int temp = board[nx][ny] + 32 -'a';
                    if(!key[temp])
                    {
                        door[temp].push({nx,ny});
                        continue;
                    }
                }
                else if(board[nx][ny] == '$')
                {
                    count++;
                }
                q.push({nx,ny});
            }
        }
        cout << count <<'\n';
    }
}
