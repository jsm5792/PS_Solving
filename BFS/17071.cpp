#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,K;
int board[500005];
int vis[2][500005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<2;i++)
    {
        fill(vis[i],vis[i]+500002,-1);
    }
    vis[0][N] = 0;
    queue<pair<int,int>> q;
    q.push({N,0});
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(auto next:{x-1,x+1,2*x})
        {
            if(next < 0 || next > 500000)
            {
                continue;
            }
            if(vis[(y+1)%2][next] != -1)
            {
                continue;
            }
            vis[(y+1)%2][next] = y+1;
            q.push({next,y+1});
        }
    }
    bool found = false;
    int curr = K;
    int t =0;
    while(curr <=500000)
    {
        if(vis[t%2][curr] <= t)
        {
            found = true;
            break;
        }
        t++;
        curr+= t;
    }
    if(found)
    {
        cout << t;
    }
    else
    {
        cout << -1;
    }
}
