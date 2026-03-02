#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int a[13];

void solve(int x, int y)
{
    if(x==M)
    {
        for(int i=0;i<M;i++)
        {
            cout << a[i]<<' ';
        }
        cout <<'\n';
        return;
    }
    for(int i=y;i<=N;i++)
    {
        a[x] = i;
        solve(x+1,i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    solve(0,1);
}
