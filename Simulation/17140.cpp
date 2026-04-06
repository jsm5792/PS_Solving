#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int r,c,k;
int board[105][105];
int n=3;
int m=3;

void change()
{
    int temp = max(n,m);
    for(int i=1;i<=temp;i++)
    {
        for(int j=i+1;j<=temp;j++)
        {
            swap(board[i][j],board[j][i]);
        }
    }
    swap(n,m);
}

void simulate(int a[])
{
    vector<pair<int,int>> v;
    int b[105] = {};
    for(int i=1;i<=m;i++)
    {
        b[a[i]]++;
    }
    for(int i=1;i<=100;i++)
    {
        if(b[i]==0)
        {
            continue;
        }
        v.push_back({b[i],i});
    }
    sort(v.begin(),v.end());
    int cnt = 1;
    for(auto i : v)
    {
        if(cnt > 100)
        {
            break;
        }
        a[cnt] = i.second;
        cnt++;
        a[cnt] = i.first;
        cnt++;
    }
    m = max(m,cnt);
    fill(a+cnt,a+m+1,0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> board[i][j];
        }
    }
    int ans = 0;
    while(board[r][c] != k && ans <= 100)
    {
        bool check = false;
        if(n < m)
        {
            change();
            check = true;
        }
        for(int i=1;i<=n;i++)
        {
            simulate(board[i]);
        }
        if(check)
        {
            change();
        }
        ans ++;

    } 
    if(ans > 100)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
