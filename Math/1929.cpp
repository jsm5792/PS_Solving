#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool isprime[1000005];
int N,M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    isprime[2] = true;
    for(int i=3;i<1000001;i++)
    {
        isprime[i]=true;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                isprime[i]=false;
                break;
            }
        }
    }
    for(int i=M;i<=N;i++)
    {
        if(isprime[i])
        {
            cout << i <<'\n';
        }
    }
}
