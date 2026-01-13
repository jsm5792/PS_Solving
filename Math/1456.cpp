#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long A,B,ans;
vector<long long> prime;
bool primes[10000005];
const int MAX = 10000000;

void isprime()
{
    for(int i=2;i<10000005;i++)
    {
        primes[i] = true;
    }
    for(long long i=2;i*i <= MAX; i++)
    {
        if(primes[i])
        {
            for(long long j=i*i; j<= MAX; j+=i)
            {
                primes[j] = false;
            }
        }
    }
    for(long long i=2;i<=MAX;i++)
    {
        if(primes[i])
        {
            prime.push_back(i);
        }
    }
}

void counting()
{
    for(long long i=0;i<prime.size();i++)
    {
        long long temp = prime[i];
        while(temp <= B/prime[i])
        {
            temp *= prime[i];
            if(temp >= A)
            {
                ans++;
            }
        }
    }
    cout << ans;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B;
    isprime();
    counting();
    
}

