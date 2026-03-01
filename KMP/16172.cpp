#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <int> v;

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

bool solve(string &s1, string &s2)
{
    int j=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]>='0' && s1[i]<='9')
        {
            continue;
        }
        while(j>0 && s1[i] != s2[j])
        {
            j = v[j-1];
        }
        if(s1[i] == s2[j])
        {
            j++;
        }
        if(j==s2.size())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    v = failure(s2);
    cout << solve(s1,s2);
}
