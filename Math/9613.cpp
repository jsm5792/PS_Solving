#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd(int x,int y)
{
    if(x==0)
    {
        return y;
    }
    else
    {
        return gcd(y%x,x);
    }
}

int a[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        for(int i=0;i<N;i++)
        {
            cin >> a[i];
        }
        long long ans = 0;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                ans += gcd(a[i],a[j]);
            }
        }
        cout << ans <<'\n';
    }
}
