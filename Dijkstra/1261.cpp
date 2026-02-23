#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
bool board[105][105];
int d[105][105];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void solve()
{
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    d[1][1] = 0;
    pq.push({0,1,1});
    while(!pq.empty())
    {
        int w,x,y;
        tie(w,x,y) = pq.top();
        pq.pop();
        if(d[x][y] != w)
        {
            continue;
        }
        for(int i=0;i<4;i++)
        {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1 > N || x1 < 1 || y1 > M || y1 < 1)
            {
                continue;
            }
            int w1 = w + board[x1][y1];
            if(w1 < d[x1][y1])
            {
                d[x1][y1] = w1;
                pq.push({w1,x1,y1});
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin >> s;
        for(int j=1;j<=M;j++)
        {
            board[i][j] = s[j-1] -'0';
        }
        fill(d[i],d[i]+M+1,1e9);
    }
    solve();
    cout << d[N][M];
}
