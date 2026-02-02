#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
long long ans;
vector<int> v[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    priority_queue<int> pq;
    for(int i=N;i>=1;i--)
    {
        for(auto j : v[i])
        {
            pq.push(j);
        }
        if(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;

}
