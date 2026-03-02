#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int a[13];
int b[13];

void solve(int x,int y)
{
    if(x == M)
    {
        for(int i=0;i<M;i++)
        {
            cout << b[i] <<' ';
        }
        cout <<'\n';
        return;
    }
    for(int i=y;i<N;i++)
    {
        b[x] = a[i];
        solve(x+1,i+1);
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a,a+N);
    solve(0,0);
}
