#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y)
{
    if(x==0)
    {
        return y;
    }
    return gcd(y%x,x);
}

long long lcm(long long x, long long y)
{
    return x/gcd(x,y)*y;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,a,b,c,d,ans;
    cin >> n >> a >> b >> c >> d;
    if(a*d > b *c)
    {
        long long temp = a;
        a = c;
        c = temp;
        temp = b;
        b = d;
        d = temp;
    }
    long long x = lcm(a,c);
    ans = LLONG_MAX;
    for(long long i=0;i<(x/a); i++)
    {
        long long temp =  i * b;
        if(n-i*a > 0)
        {
            temp += (((n- i*a -1)/c) +1) * d;

        }
        ans = min(ans, temp);
    }
    cout << ans;
}
