#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,ans;
bool isprime[4000005];
long long C[1000000];
vector<int> v;

void prime()
{
    for(int i=2;i<=N;i++)
    {
        isprime[i]=true;
    }
    for(int i=2;i*i<=N;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=N;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    for(int i=2;i<=N;i++)
    {
        if(isprime[i])
        {
            v.push_back(i);
            C[v.size()] = C[v.size()-1] + v.back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    prime();
    int end=0;
    for(int i=0;i<v.size();i++)
    {
        while(end<v.size() && C[end]-C[i] <N)
        {
            end++;
        }
        if(C[end]-C[i]==N)
        {
            ans++;
        }
        if(end==v.size() && C[end]-C[i] < N)
        {
            break;
        }
    }
    cout << ans;


}
