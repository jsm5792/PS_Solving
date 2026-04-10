#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Shark
{
    int r,c,s,d,z;
    bool dead=false;
};

int R,C,M,ans;
int board[105][105];
Shark sharks[10005];
int dr[5] = {0,-1,1,0,0};
int dc[5] = {0,0,0,1,-1};

void move_sharks()
{
    int nxt[105][105] = {};
    for(int i=1;i<=M;i++)
    {
        if(sharks[i].dead)
        {
            continue;
        }
        
        Shark &cur = sharks[i];
        int speed = cur.s;
        if(cur.d<=2)
        {
            speed %= (2*(R-1));
        }
        else
        {
            speed %= (2*(C-1));
        }
        int cr = cur.r;
        int cc = cur.c;
        int cd = cur.d;
        
        for(int j=0;j<speed;j++)
        {
            if(cd==1 && cr==1)
            {
                cd=2;
            }
            else if(cd==2 && cr==R)
            {
                cd=1;
            }
            else if(cd==3 && cc==C)
            {
                cd=4;
            }
            else if(cd==4 && cc==1)
            {
                cd=3;
            }
            cr += dr[cd];
            cc += dc[cd];
        }
        
        cur.r = cr;
        cur.c = cc;
        cur.d = cd;
        
        if(nxt[cr][cc]==0)
        {
            nxt[cr][cc]=i;
        }
        else
        {
            int prev = nxt[cr][cc];
            if(sharks[prev].z < cur.z)
            {
                sharks[prev].dead = true;
                nxt[cr][cc] = i;
            }
            else
            {
                cur.dead = true;
            }
        }
    }
    
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            board[i][j]=nxt[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> M;

    for(int i=1;i<=M;i++)
    {
        cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
        board[sharks[i].r][sharks[i].c] = i;
    }
    
    for(int j=1;j<=C;j++)
    {
        for(int i=1;i<=R;i++)
        {
            if(board[i][j]>0)
            {
                int target = board[i][j];
                ans += sharks[target].z;
                sharks[target].dead = true;
                board[i][j] = 0;
                break;
            }
        }
        move_sharks();
    }
    cout << ans;
}