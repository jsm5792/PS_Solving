#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
long long ans;

void sum_v(vector<int> v)
{
    while(v.size()>1)
    {
        ans += *(v.end()-1) * *(v.end()-2);
        v.pop_back();
        v.pop_back();
    }
    if(v.size())
    {
        ans+= v[0];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> p,q;
    for(int i=0;i<N;i++)
    {
        int a;
        cin >> a;
        if(a==1)
        {
            ans++;
        }
        else if(a>0)
        {
            p.push_back(a);
        }
        else
        {
            q.push_back(a);
        }
    }
    sort(p.begin(),p.end());
    sort(q.begin(),q.end(),greater<>());
    sum_v(p);
    sum_v(q);
    cout << ans;
}
