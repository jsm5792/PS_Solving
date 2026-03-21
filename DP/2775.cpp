#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T,N,K;
int a[20][20];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int i=0;i<20;i++)
    {
        fill(a[i],a[i]+18,0);
    }
    for(int i=1;i<20;i++)
    {
        a[0][i] = i;
    }
    for(int i=1;i<20;i++)
    {
        for(int j=1;j<20;j++)
        {
            a[i][j] = a[i][j-1] + a[i-1][j];
        }
    }
    while(T--)
    {
        cin >> K;
        cin >> N;
        cout << a[K][N]<<'\n';
    }
}
