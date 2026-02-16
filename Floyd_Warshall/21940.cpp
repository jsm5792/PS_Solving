#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int board[205][205];
int fr[205];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        fill(board[i],board[i]+N+1,500000);
        board[i][i] = 0;
    }
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        board[a][b] = c;
    }
    cin >> K;
    for(int i=1;i<=K;i++)
    {
        cin >> fr[i];
    }
    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(board[i][j] > board[i][k] + board[k][j])
                {
                    board[i][j] = board[i][k]  + board[k][j];
                }
            }
        }
    }
    vector<pair<int,int>> v;
    for(int i=1;i<=N;i++)
    {
        int temp =0;
        for(int j=1;j<=K;j++)
        {
            temp = max(temp, board[i][fr[j]]+board[fr[j]][i]);
        }
        v.push_back({temp,i});
    }
    
    sort(v.begin(),v.end());
    cout << v[0].second;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].first != v[i-1].first)
        {
            break;
        }
        cout <<" "<< v[i].second;
    }
    

}
