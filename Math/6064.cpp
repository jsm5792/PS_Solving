#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd(int x,int y)
{
    if(x==0)
    {
        return y;
    }
    return gcd(y%x,x);
}

int lcm(int x, int y)
{
    return x / gcd(x, y) * y;
}


int solve(int m,int n, int x, int y)
{
    if(x==m)
    {
        x=0;
    }
    if(y==n)
    {
        y=0;
    }
    int l = lcm(m,n);
    for(int i=x;i<=l;i+=m)
    {
        if(i==0)
        {
            continue;
        }
        if(i%n==y)
        {
            return i;
        }
    }
    return -1;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--)
    {
        int m,n,x,y;
        cin >> m >> n >> x >> y;
        cout << solve(m,n,x,y) <<'\n';
    }
}
