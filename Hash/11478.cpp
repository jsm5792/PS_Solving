#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    unordered_set<string> m;
    for(int i=0;i<s.size();i++)
    {
        string temp = "";
        for(int j=i;j<s.size();j++)
        {
            temp +=s[j];
            m.insert(temp);
        }
    }
    cout << m.size();
}
