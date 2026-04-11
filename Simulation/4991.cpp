#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int vis[25][25];
char board[25][25];
int w,h;
int x,y;
vector<pair<int,int>> v;
int d[11][11];

int BFS(int i1, int i2)
{
    for(int i=0;i<25;i++)
    {
        for(int j=0;j<25;j++)
        {
            vis[i][j] = -1;
        }
    }
    queue<pair<int,int>> q;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    q.push({v[i1].first,v[i1].second});
    vis[v[i1].first][v[i1].second] = 0;
    while(!q.empty())
    {
        int cx,cy;
        tie(cx,cy) = q.front();
        q.pop();
        if(cx == v[i2].first && cy == v[i2].second)
        {
            return vis[cx][cy];
        }
        for(int i=0;i<4;i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx<0 || ny<0 || nx>=h || ny>=w)
            {
                continue;
            }
            if(vis[nx][ny]!=-1 || board[nx][ny]=='x')
            {
                continue;
            }
            q.push({nx,ny});
            vis[nx][ny] = vis[cx][cy] + 1;
        }

    }
    return -1;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        int ans = 1e9;
        v.clear();
        for(int i=0;i<11;i++)
        {
            for(int j=0;j<11;j++)
            {
                d[i][j] = -1;
            }
        }
        cin >> w >> h;
        if(w==0 && h==0)
        {
            break;
        }
        for(int i=0;i<h;i++)
        {
            string s;
            cin >> s;
            for(int j=0;j<w;j++)
            {
                board[i][j] = s[j];
                if(board[i][j]=='o')
                {
                    x = i;
                    y = j;
                }
                else if(board[i][j]=='*')
                {
                    v.push_back({i,j});
                }
            }
        }
        v.insert(v.begin(),{x,y});
        
        bool check = false;
        for(int i=0;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                int dist = BFS(i,j);
                if(dist == -1)
                {
                    check = true;
                    break;
                }
                d[i][j] = dist;
                d[j][i] = dist;
            }
            if(check)
            {
                break;
            }

        }
        if(check)
        {
            cout << -1<<'\n';
            continue;
        }
        vector<int> p;
        for(int i=1;i<v.size();i++)
        {
            p.push_back(i);
        }
        do
        {
            int curr = d[0][p[0]];
            for(int i=0;i<p.size()-1;i++)
            {
                curr += d[p[i]][p[i+1]];
            }
            ans = min(curr,ans);
        } while (next_permutation(p.begin(),p.end()));
        
        cout << ans <<'\n';
        

    }
}
