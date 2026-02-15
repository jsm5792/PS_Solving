#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,K;

int a[1005];
vector <int> v(1005,-1);
tuple<int,int,int> edge[100005];

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
    if(x==y)
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
    cin >> N >> M >> K;
    for(int i=0;i<K;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<K;i++)
    {
        group(a[0],a[i]);
    }
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        edge[i] = {z,x,y};
    }
    sort(edge,edge+M);
    long long ans =0;
    int cnt =0;
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        tie(x,y,z) = edge[i];
        if(!group(y,z))
        {
            continue;
        }
        cnt++;
        ans+=x;
        if(cnt == N-1)
        {
            break;
        }
    }
    cout << ans;
}
