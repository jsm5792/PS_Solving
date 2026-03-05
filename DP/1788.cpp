#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
long long p[1000005];
long long m[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    p[0] = 0;
    m[0] = 0;
    p[1] = 1;
    m[1] = 1;
    if(N > 0)
    {
        for(int i=2;i<=N;i++)
        {
            p[i] = (p[i-1]+p[i-2]) % 1000000000;
        }
        cout << "1\n" << p[N];
    }
    else if(N==0)
    {
        cout << "0\n0";
    }
    else
    {
        N *= -1;
        for(int i=2;i<=N;i++)
        {
            m[i] = (m[i-2]-m[i-1]) % 1000000000;
        }
        if(m[N]<0)
        {
            cout << "-1\n"<<abs(m[N]);
        }
        else
        {
            cout << "1\n"<<m[N];
        }
    }

}
