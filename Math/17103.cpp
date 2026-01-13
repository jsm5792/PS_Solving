#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isprime[1000005];

void prime()
{
    for(int i=2;i<=1000000;i++)
    {
        isprime[i]=true;
    }
    for(int i=2;i*i<=1000000;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=1000000;j+= i)
            {
                isprime[j]=false;
            }
        }
    }

}

int ans(int N)
{
    int count = 0;
    for(int i=2;i<=N/2;i++)
    {
        if(isprime[i] && isprime[N-i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    prime();
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        cout << ans(N) <<'\n';
    }
}
