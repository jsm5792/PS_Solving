#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long gcd(long long x,long long y)
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
long long lcm(long long x,long long y)
{
    return x/gcd(x,y)*y;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >>T;
    while(T--)
    {
        long long a,b;
        cin >> a >> b;
        cout <<lcm(a,b)<<'\n';
    }
}
