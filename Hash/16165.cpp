#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    unordered_map<string, string> m1;
    unordered_map<string, vector<string>> m2;
    for(int i=0;i<N;i++)
    {
        string a,b;
        cin >> a;
        int x;
        cin >> x;
        for(int j=0;j<x;j++)
        {
            cin >> b;
            m1[b] = a;
            m2[a].push_back(b);
        }
        sort(m2[a].begin(),m2[a].end());
    }
    int y;
    string c;
    for(int i=0;i<M;i++)
    {
        cin >> c >> y;
        if(y==1)
        {
            cout << m1[c]<<'\n';
        }
        else
        {
            for(auto j : m2[c])
            {
                cout << j << '\n';
            }
        }
    }


}
