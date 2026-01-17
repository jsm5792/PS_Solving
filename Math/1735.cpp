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
    return x/gcd(x,y)*y;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,y,z,w,p,q;
    cin >> x >> y;
    cin >> z >> w;
    p =  lcm(y,w) / y * x  + lcm(y,w)/w * z;
    q = lcm(y,w);
    cout << p/gcd(p,q) << ' '<< q/gcd(p,q);
}
