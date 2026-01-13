#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isprime[10005];

void prime()
{
    for(int i=2;i<=10000;i++)
    {
        isprime[i] = true;
    }
    for(int i=2;i*i<=10000;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=10000;j+=i)
            {
                isprime[j] = false;
            }
        }
    }
}

void divide(int N)
{
    for(int i=N/2;i>=2;i--)
    {
        if(isprime[i] && isprime[N-i])
        {
            cout << i << ' '<< N-i <<'\n';
            return;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    prime();
    while(T--)
    {
        int N;
        cin >> N;
        divide(N);        
    }
}
