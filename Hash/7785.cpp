#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_set <string> s;
    int N;
    cin >> N;
    while(N--)
    {
        string a,b;
        cin >> a >> b;
        if(b=="enter")
        {
            s.insert(a);
        }
        else
        {
            s.erase(a); 
        }
    }
    vector<string> v(s.begin(),s.end());
    sort(v.begin(),v.end(),greater<string>());
    for(auto i : v)
    {
        cout << i << '\n';
    }
}
