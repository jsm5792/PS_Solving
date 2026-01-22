#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
int a[1000005];
int b[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    vector <int> v;
    for(int i=0;i<N;i++)
    {
        if(v.empty() || v.back() < a[i])
        {
            b[i] = v.size();
            v.push_back(a[i]);
        }
        else
        {
            int index = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
            v[index] = a[i];
            b[i] = index;
        }
    }
    cout << v.size()<< '\n';
    stack <int> s;
    int target = v.size()-1;
    for(int i=N-1;i>=0;i--)
    {
        if(b[i] == target)
        {
            s.push(a[i]);
            target--;
        }
    }
    while(!s.empty())
    {
        cout << s.top() <<' ';
        s.pop();
    }
}
