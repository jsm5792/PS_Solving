#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Person
{
    int sr, sc, er, ec;
};

int N, M, Fuel;
int board[25][25];
int dist[25][25];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
Person p[405];
bool finished[405];
int tr, tc;

int bfs(int sr, int sc, int er, int ec)
{
    for(int i=1;i<=N;i++)
    {
        fill(dist[i]+1, dist[i]+N+1, -1);
    }
    queue<pair<int, int>> q;
    q.push({sr, sc});
    dist[sr][sc] = 0;
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if(cur.first==er&&cur.second==ec)
        {
            return dist[cur.first][cur.second];
        }
        for(int i=0;i<4;i++)
        {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if(nr<1||nr>N||nc<1||nc>N||board[nr][nc]==1||dist[nr][nc]!=-1)
            {
                continue;
            }
            dist[nr][nc] = dist[cur.first][cur.second] + 1;
            q.push({nr, nc});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> Fuel;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> board[i][j];
        }
    }
    cin >> tr >> tc;
    for(int i=1;i<=M;i++)
    {
        cin >> p[i].sr >> p[i].sc >> p[i].er >> p[i].ec;
    }
    for(int i=0;i<M;i++)
    {
        bfs(tr, tc, -1, -1);
        int min_dist = 1e9;
        int target = -1;
        for(int j=1;j<=M;j++)
        {
            if(finished[j])
            {
                continue;
            }
            int d = dist[p[j].sr][p[j].sc];
            if(d==-1)
            {
                continue;
            }
            if(d<min_dist)
            {
                min_dist = d;
                target = j;
            }
            else if(d==min_dist)
            {
                if(p[j].sr<p[target].sr)
                {
                    target = j;
                }
                else if(p[j].sr==p[target].sr&&p[j].sc<p[target].sc)
                {
                    target = j;
                }
            }
        }
        if(target==-1||Fuel-min_dist<0)
        {
            cout << -1;
            return 0;
        }
        Fuel = Fuel - min_dist;
        int move = bfs(p[target].sr, p[target].sc, p[target].er, p[target].ec);
        if(move==-1||Fuel-move<0)
        {
            cout << -1;
            return 0;
        }
        Fuel = Fuel + move;
        tr = p[target].er;
        tc = p[target].ec;
        finished[target] = true;
    }
    cout << Fuel;
}
