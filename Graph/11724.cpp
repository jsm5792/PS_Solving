#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector <int> v[1005];
bool a[1005];
int N,M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    while(M--)
    {
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int num = 0;
    for(int i=1;i<=N;i++)
    {
        if(a[i])
        {
            continue;
        }
        num++;
        queue<int> q;
        q.push(i);
        a[i] = true;
        while(!q.empty())
        {
            int cur =q.front();
            q.pop();
            for(auto next : v[cur])
            {
                if(a[next])
                {
                    continue;
                }
                q.push(next);
                a[next] = true;
            }
        }
    }
    cout << num;
}
