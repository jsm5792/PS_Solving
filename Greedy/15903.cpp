#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for(int i=0;i<N;i++)
    {
        long long a;
        cin >> a;
        q.push(a);
    }
    for(int i=0;i<M;i++)
    {
        long long a,b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a+b);
        q.push(a+b);
    }
    long long ans=0;
    for(int i=0;i<N;i++)
    {
        ans += q.top();
        q.pop();        
    }
    cout << ans;
}
