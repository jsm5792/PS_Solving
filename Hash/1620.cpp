#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map <int,string> m1;
    unordered_map <string,int> m2;

    int N,M;
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin >> s;
        m1[i] = s;
        m2[s] = i;
    }
    for(int i=0;i<M;i++)
    {
        string s;
        cin >> s;
        if(isdigit(s[0]))
        {
            int num = stoi(s);
            cout << m1[num] <<'\n';
        }
        else
        {
            cout << m2[s]<<'\n';
        }
    }


}
