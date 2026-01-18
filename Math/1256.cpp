#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int a[302][302];
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1;i<=200;i++)
    {
        a[i][0]=1;
        a[i][i]=1;
        for(int j=1;j<i;j++)
        {
            a[i][j] = a[i-1][j] + a[i-1][j-1];
            if(a[i][j]>1000000000)
            {
                a[i][j] = 1000000005;
            }
        }
    }
    while(N && M)
    {
        if(K > a[N+M-1][N-1])
        {
            K-= a[N+M-1][N-1];
            s+='z';
            M--;
        }
        else
        {
            s+='a';
            N--;
        }
    }
    while(N--)
    {
        s+='a';
    }
    while(M--)
    {
        s+='z';
    }
    if(K>1)
    {
        cout << -1;
    }
    else
    {
        cout << s;
    }
}
