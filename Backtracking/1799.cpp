#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int board[13][13];
vector<pair<int,int>> black,white;

int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};

bool diag1[35];
bool diag2[35];

int ans;
int max_ans;

void solve(vector<pair<int,int>>& v, int idx,int cnt)
{
    if(idx == v.size())
    {
        ans = max(ans, cnt);
        return;
    }
    int x = v[idx].first;
    int y = v[idx].second;
    if(diag1[x-y+N]==false && diag2[x+y]==false)
    {
        diag1[x-y+N] = true;
        diag2[x+y] = true;
        solve(v,idx+1,cnt+1);
        diag1[x-y+N] = false;
        diag2[x+y] = false;
                
    }
    solve(v,idx+1,cnt);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> board[i][j];
            if(board[i][j])
            {
                if((i+j)%2 == 0)
                {
                    black.push_back({i,j});
                }
                else
                {
                    white.push_back({i,j});
                }
            }
        }
    }
    solve(black,0,0);
    max_ans += ans;
    ans = 0;
    solve(white,0,0);
    max_ans += ans;
    cout << max_ans;

}
