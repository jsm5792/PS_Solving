#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isprime[100005];
vector <int> v;

void prime()
{
    for(int i=2;i<=100000;i++)
    {
        isprime[i] = true;
    }
    for(int i=2;i*i<=100000;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=100000;j+=i)
            {
                isprime[j] = false;
            }
        }
    }
    for(int i=2;i<=100000;i++)
    {
        if(isprime[i])
        {
            v.push_back(i);
        }
    }
}

void divide(int a)
{
    int curr = a;
    int index = 0;
    while(curr!=1)
    {
        if(curr % v[index]==0)
        {
            int count = 0;
            while(curr % v[index]==0)
            {
                curr /= v[index];
                count++;
            }
            cout << v[index] << ' '<< count <<'\n';
        }
        index++;
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >>T;
    prime();
    while(T--)
    {
        int N;
        cin >> N;
        divide(N);
    }
}
