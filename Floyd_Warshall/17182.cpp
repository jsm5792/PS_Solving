#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,K;
int board[15][15];
bool vis[15];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> board[i][j];
        }
    }
    for(int k=0;k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(board[i][j] > board[i][k]+board[k][j])
                {
                    board[i][j] = board[i][k] + board[k][j];
                }
            }
        }
    }
    vector <int> v;
    for(int i=0;i<N;i++)
    {
        if(i!=K)
        {
            v.push_back(i);
        }
    }
    int ans = 100000000;
    do
    {
        int temp = board[K][v[0]];
        for(int i=1;i<N-1;i++)
        {
            temp += board[v[i-1]][v[i]];
        }
        ans = min(ans,temp);
    } while (next_permutation(v.begin(),v.end()));
    cout << ans;
    
}
