#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
    {
        priority_queue <long long,vector<long long>,greater<long long>> pq;
        int K;
        long long ans = 0;
        cin >> K;
        while(K--)
        {
            long long temp;
            cin >> temp;
            pq.push(temp);
        }
        while(pq.size()>1)
        {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(x+y);
            ans += x+y;
        }
        cout << ans <<'\n';
    }
}
