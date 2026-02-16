#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int board[105][105];
int nxt[105][105];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        fill(board[i],board[i]+N+1,1000000000);
    }
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b],c);
        nxt[a][b] = b;
    }
    for(int i=1;i<=N;i++)
    {
        board[i][i] = 0;
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(board[i][j] > board[i][k] + board[k][j])
                {
                    board[i][j] = board[i][k] + board[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(board[i][j]==1000000000)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << board[i][j]<<" ";
            }
        }
        cout << '\n';
    }
    vector <int> v;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(board[i][j]==0 || board[i][j]==1000000000)
            {
                cout << 0 <<'\n';
            }
            else
            {
                v.clear();
                int temp = i;
                while(1)
                {
                    v.push_back(temp);
                    if(temp == j)
                    {
                        break;
                    }
                    temp = nxt[temp][j];
                }
                cout << v.size();
                for(auto x : v)
                {
                    cout << " "<< x;
                }
                cout <<'\n';
            }
        }
    }
}
