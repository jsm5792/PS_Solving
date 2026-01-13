#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    deque<int> q;
    for(auto i:s)
    {
        q.push_back(i-'0');
    }
    sort(q.begin(),q.end());
    int sum = 0;
    for(int i=0;i<q.size();i++)
    {
        sum += q[i];
    }
    if(sum%3==0 && q[0]==0)
    {
        for(int i=q.size()-1;i>=0;i--)
        {
            cout << q[i];
        }
    }
    else
    {
        cout << -1;
    }
}
