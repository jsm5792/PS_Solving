#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
pair <int,int> a[500005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a,a+N,greater<pair<int,int>>());
    multiset <int> m;
    for(int i=0;i<N;i++)
    {
        auto it = m.lower_bound(-a[i].second + 1);
        if(it == m.end())
        {
            m.insert(-1);
        }
        else
        {
            auto temp =*it;
            m.erase(it);
            m.insert(temp-1);
        }
    }
    cout << m.size();
}
