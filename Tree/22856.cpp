#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,end_point;
pair<int,int> v[100005];
bool visit[100005];
int ans = 0;
bool finish = false;


void find(int curr)
{
    if(curr==-1)
    {
        return;
    }
    find(v[curr].first);
    end_point = curr;
    find(v[curr].second);
}

void M_DFS(int curr)
{
    int next_l = v[curr].first;
    int next_r = v[curr].second;
    if(next_l != -1)
    {
        ans++;
        M_DFS(next_l);
        if(finish)
        {
            return;
        }
        ans++;
    }
    if(curr == end_point)
    {
        finish = true;
        return;
    }
    if(next_r != -1)
    {
        ans++;
        M_DFS(next_r);
        if(finish)
        {
            return;
        }
        ans++;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a] = {b,c};
    }

    find(1);
    M_DFS(1);
    cout << ans;
}
