#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
char board[10][10];

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,1,-1,-1,0,1};

unordered_map <string, int> m;

void dfs(int x, int y, string s)
{
    m[s]++;
    if(s.size()==5)
    {
        return;
    }
    for(int i=0;i<8;i++)
    {
        int temp_x = (x+dx[i]+N) % N;
        int temp_y = (y+dy[i]+M) % M;
        dfs(temp_x,temp_y, s + board[temp_x][temp_y]);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
    {
        string s;
        cin >> s;
        for(int j=0;j<M;j++)
        {
            board[i][j] = s[j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            string s = "";
            dfs(i,j,s+board[i][j]);
        }
    }
    while(K--)
    {
        string s;
        cin >> s;
        cout << m[s] <<'\n';
    }

}
