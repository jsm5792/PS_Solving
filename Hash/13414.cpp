#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int K,L;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<string, int> m;
    cin >> K >> L;
    vector <string> v(L);
    for(int i=0;i<L;i++)
    {
        cin >> v[i];
        m[v[i]] = i;
    }
    int cnt = 0;
    for(int i=0;i<L;i++)
    {
        if(m[v[i]]==i)
        {
            cout << v[i] <<'\n';
            cnt++;
        }
        if(cnt ==K)
        {
            break;
        }
    }

}
