#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int a[105];

int gcd(int x,int y)
{
    if(x==0)
    {
        return y;
    }
    return gcd(y%x,x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<N;i++)
    {
        int b = gcd(a[0],a[i]);
        cout << a[0]/b <<'/'<< a[i]/b <<'\n';
    }
}
