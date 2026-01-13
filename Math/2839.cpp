#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int a[10000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    a[3]=1;
    a[5]=1;
    for(int i=6;i<=N;i++)
    {
        if(a[i-3]!=0 && a[i-5]!=0)
        {
            a[i]=min(a[i-3],a[i-5])+1;
        }
        else if(a[i-3]==0 && a[i-5]==0)
        {
            a[i]=0;
        }
        else if(a[i-3]==0)
        {
            a[i]=a[i-5]+1;
        }
        else
        {
            a[i]=a[i-3]+1;
        }
    }
    if(a[N]==0)
    {
        cout << -1;
    }
    else
    {
        cout << a[N];
    }
}
