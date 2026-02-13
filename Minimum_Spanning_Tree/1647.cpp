#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector <int> v(100005,-1);
tuple<int,int,int> edge[1000005];

int find(int x)
{
    if(v[x]<0)
    {
        return x;
    }
    return v[x] = find(v[x]);
}

bool group(int x,int y)
{
    x = find(x);
    y = find(y);
    if(x == y)
    {
        return false;
    }
    if(v[x]==v[y])
    {
        v[x]--;
    }
    if(v[x]<v[y])
    {
        v[y] = x;
    }
    else
    {
        v[x] = y;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge[i] = {c,a,b};
    }
    sort(edge,edge + M);
    
    long long ans = 0;
    int count = 0;
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        tie(x,y,z) = edge[i];
        if(!group(y,z))
        {
            continue;
        }
        count++;
        if(count == N-1)
        {
            break;
        }
        ans += x;
    }
    cout << ans;
}
