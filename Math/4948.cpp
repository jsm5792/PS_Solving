#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isprime[300000];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m = 2*123456;
    for(int i=2;i<=m;i++)
    {
        isprime[i]=true;
    }
    int index =2;
    while(index * index <= m)
    {
        for(int i=2;i<= m/index; i++)
        {
            if(isprime[i * index])
            {
                isprime[i*index] = false;
            }
        }
        index++;
    }
    while(1)
    {
        int n;
        cin >> n;
        if(n==0)
        {
            break;
        }
        else
        {
            int count=0;
            for(int i=n+1;i<=2*n;i++)
            {
                if(isprime[i])
                {
                    count++;
                }
            }
            cout << count <<'\n';
        }
    }
}
