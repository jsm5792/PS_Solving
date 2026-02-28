#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> failure(string& s)
{
    vector<int> f(s.size());
    int j = 0;
    for(int i=1;i<s.size();i++)
    {
        while(j>0 && s[i] != s[j])
        {
            j = f[j-1];
        }
        if(s[i] == s[j])
        {
            f[i] = ++j;
        }
    }
    return f;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,p;
    cin >> s >> p;
    vector<int> f = failure(p);
    int j = 0;
    for(int i=0;i<s.size();i++)
    {
        while(j>0 && s[i] != p[j])
        {
            j = f[j-1];
        }
        if(s[i] == p[j])
        {
            j++;
        }
        if(j==p.size())
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}
