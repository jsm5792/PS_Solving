#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,Q;
pair<int,int> dog[505];
int dog_t[505];
int board[505][505];
int total[505][505];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> Q;
    for(int i=1;i<=N;i++)
    {
        cin >> dog_t[i];
        dog[i] = {dog_t[i],i};
    }
    sort(dog+1,dog+N+1);
    for(int i=1;i<=N;i++)
    {
        fill(board[i],board[i]+N+1,100000000);
        fill(total[i],total[i]+N+1,100000000);
        board[i][i] = 0;
        total[i][i] = dog_t[i];
    }
    for(int i=0;i<M;i++)
    {
        int a,b,d;
        cin >> a >> b >> d;
        board[a][b] = min(board[a][b],d);
        board[b][a] = min(board[b][a],d);
        total[a][b] = board[a][b] + max(dog_t[a],dog_t[b]);
        total[b][a] = board[b][a] + max(dog_t[a],dog_t[b]);
    }
    for(int k=1;k<=N;k++)
    {
        int temp = dog[k].second;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(board[i][temp]==100000000 || board[temp][j]==100000000)
                {
                    continue;
                }
                board[i][j] = min(board[i][j],board[i][temp]+board[temp][j]);
                total[i][j] = min(total[i][j],board[i][temp]+board[temp][j]+max({dog_t[i],dog_t[j],dog_t[temp]}));
            }
        }
    }
    while(Q--)
    {
        int s,e;
        cin >> s >> e;
        if(total[s][e]==100000000)
        {
            cout<<"-1\n";
        }
        else
        {
            cout << total[s][e] <<'\n';
        }
    }
}
