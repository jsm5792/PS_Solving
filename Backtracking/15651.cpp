#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int a[12];

void solve(int x)
{
    if(x == M)
    {
        for(int i=0;i<M;i++)
        {
            cout << a[i] <<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=N;i++)
    {
        a[x] = i;
        solve(x+1);
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    solve(0);
}
