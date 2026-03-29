#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,K;
int a[105];
int d[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=1;i<=N;i++)
    {
        cin >> a[i];
    }

    fill(d,d+K+1,100001);
    d[0]=0;

    for(int i=1;i<=N;i++)
    {
        for(int j=a[i];j<=K;j++)
        {
            if(d[j]>d[j-a[i]]+1)
            {
                d[j]=d[j-a[i]]+1;
            }
        }
    }

    if(d[K]==100001)
    {
        cout << -1;
    }
    else
    {
        cout << d[K];
    }

}
