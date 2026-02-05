#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int x,y,a,b,ans;
vector <int> v[105];
int c[105];

void DFS(int curr)
{
    c[curr] = 1;
    for(auto i : v[curr])
    {
        if(c[i])
        {
            continue;
        }
        ans++;
        DFS(i);
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    while(y--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1);
    cout << ans;
}
