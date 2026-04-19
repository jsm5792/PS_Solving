#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dice[10];
int horse[4];
int nxt[33];
int blue[33];
int score[33];
bool occupied[33];
int ans = 0;

void init()
{
    for(int i = 0; i <= 20; i++)
    {
        nxt[i] = i + 1;
        score[i] = i * 2;
    }
    nxt[20] = 32;
    nxt[32] = 32;
    blue[5] = 21;
    nxt[21] = 22;
    nxt[22] = 23;
    nxt[23] = 29;
    blue[10] = 24;
    nxt[24] = 25;
    nxt[25] = 29;
    blue[15] = 26;
    nxt[26] = 27;
    nxt[27] = 28;
    nxt[28] = 29;
    nxt[29] = 30;
    nxt[30] = 31;
    nxt[31] = 20;
    score[21] = 13;
    score[22] = 16;
    score[23] = 19;
    score[24] = 22;
    score[25] = 24;
    score[26] = 28;
    score[27] = 27;
    score[28] = 26;
    score[29] = 25;
    score[30] = 30;
    score[31] = 35;
    score[32] = 0;
}

void solve(int cnt, int sum)
{
    if(cnt == 10)
    {
        ans = max(ans, sum);
        return;
    }
    for(int i=0;i<4;i++)
    {
        int cur = horse[i];
        if(cur==32)
        {
            continue;
        }
        int move = dice[cnt];
        int next = (blue[cur]>0)?blue[cur]:nxt[cur];
        for(int j=1;j<move;j++)
        {
            next = nxt[next];
        }
        if(next!=32&&occupied[next])
        {
            continue;
        }
        occupied[cur] = false;
        occupied[next] = true;
        horse[i] = next;
        solve(cnt+1, sum+score[next]);
        horse[i] = cur;
        occupied[next] = false;
        occupied[cur] = true;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<10;i++)
    {
        cin>>dice[i];
    }
    init();
    solve(0, 0);
    cout<<ans;
}
