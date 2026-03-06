#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int board[30][30];
bool visit[30][30];
vector<int> v;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        string s;
        cin >> s;
        for(int j=0;j<N;j++)
        {
            board[i][j] = s[j] - '0';
        }
    }
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j]==0 || visit[i][j])
            {
                continue;
            }
            int area = 0;
            visit[i][j] = true;
            q.push({i,j});
            while(!q.empty())
            {
                area++;
                int x,y;
                tie(x,y) = q.front();
                q.pop();
                for(int d=0;d<4;d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx <0 || ny<0 || nx>=N || ny>=N)
                    {
                        continue;
                    }
                    if(board[nx][ny]==0 || visit[nx][ny])
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
    cout << v.size() <<'\n';
    sort(v.begin(),v.end());
    for(auto i : v)
    {
        cout << i <<'\n';
    }

}
