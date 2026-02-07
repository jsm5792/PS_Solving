#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,M,T,ans;
bool truth[55];
vector<int> party[55];
vector<int> v[55];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    cin >> T;
    queue<int> q;
    while(T--)
    {
        int x;
        cin >> x;
        truth[x] = true;
        q.push(x);
    }
    for(int i=0;i<M;i++)
    {
        int num;
        cin >> num;
        while(num--)
        {
            int x;
            cin >> x;
            party[i].push_back(x);
        }
        for(int j=0;j<party[i].size();j++)
        {
            for(int k=j+1;k<party[i].size();k++)
            {
                int x = party[i][j];
                int y = party[i][k];
                v[x].push_back(y);
                v[y].push_back(x);
            }
        }
    }
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(auto next : v[curr])
        {
            if(truth[next])
            {
                continue;
            }
            truth[next] = true;
            q.push(next);
        }
    }
    for(int i=0;i<M;i++)
    {
        bool check = true;
        for(auto j : party[i])
        {
            if(truth[j])
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            ans++;
        }
    }
    cout << ans;
}
