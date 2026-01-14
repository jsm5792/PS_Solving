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

int lcm(int x,int y)
{
    return x/gcd(x,y)*y;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int E,S,M;
    cin >> E >> S >> M;
    E--;
    S--;
    M--;
    int i = E;
    while(i%28 != S)
    {
        i+=15;
    }
    int j = lcm(15,28);
    while(i%19 != M)
    {
        i+= j;
    }
    cout << i+1;
}
