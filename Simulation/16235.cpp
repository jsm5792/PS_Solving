#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int board[15][15];
int wint[15][15];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};
deque <int> dq[15][15];
queue <tuple<int,int,int>> dead;
queue <tuple<int,int>> baby;
vector <tuple<int,int,int>> v;

void spring()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(dq[i][j].empty())
            {
                continue;
            }
            deque<int> alive;
            while(!dq[i][j].empty() && dq[i][j].front() <= board[i][j])
            {
                board[i][j] -= dq[i][j].front();
                alive.push_back(dq[i][j].front()+1);
                dq[i][j].pop_front();
            }
            while(!dq[i][j].empty())
            {
                dead.push({i,j,dq[i][j].front()});
                dq[i][j].pop_front();
            }
            while(!alive.empty())
            {
                dq[i][j].push_back(alive.front());
                if(alive.front()%5 ==0)
                {
                    baby.push({i,j});
                }
                alive.pop_front();
            }
        }
    }
}

void summer()
{
    while(!dead.empty())
    {
        int x,y,z;
        tie(x,y,z) = dead.front();
        dead.pop();
        board[x][y] += z/2;
    }
}

void fall()
{
    while(!baby.empty())
    {
        int x,y;
        tie(x,y) = baby.front();
        baby.pop();
        for(int i=0;i<8;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <1 || ny < 1 || nx >N || ny >N)
            {
                continue;
            }
            dq[nx][ny].push_front(1);
        }
    }
}

void winter()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            board[i][j] += wint[i][j];
        }
    }

}

void simulate()
{
    spring();
    summer();
    fall();
    winter();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            board[i][j] = 5;
            cin >> wint[i][j];
        }
    }
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        dq[x][y].push_back(z);
    }
    while(K--)
    {
        simulate();
    }
    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            ans += dq[i][j].size();
        }
    }
    cout << ans;

}
