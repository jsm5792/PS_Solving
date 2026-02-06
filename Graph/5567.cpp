#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,M;
int ans;

vector <int> v[505];
int a[505];

void BFS()
{
    fill(a,a+505,-1);
    queue <int> q;
    q.push(1);
    a[1] = 0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        if(a[curr] >= 2)
        {
            continue;
        }
        for(auto next : v[curr])
        {
            if(a[next]!=-1)
            {
                continue;
            }
            a[next] = a[curr] +1;
            q.push(next);
            ans++;
        }
    }
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    while(M--)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    BFS();
    cout << ans;
}
