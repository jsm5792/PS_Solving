#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,K;
vector <pair<int,int>> v;
multiset<int> m;
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin >> x >> y;
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<K;i++)
    {
        int x;
        cin >> x;
        m.insert(x);
    }
    for(int i=N-1;i>=0;i--)
    {
        int a,b;
        a = v[i].first;
        b = v[i].second;
        auto it = m.lower_bound(b);
        if(it == m.end())
        {
            continue;
        }
        ans += a;
        m.erase(it);
    }
    cout << ans;

}
