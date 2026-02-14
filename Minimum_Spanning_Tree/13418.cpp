#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
vector <int> v(1005,-1);
tuple<int,int,int> edge1[500005];
tuple<int,int,int> edge2[500005];


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
    cin >> N >> M;
    M++;
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge1[i] = {c,a,b};
        edge2[i] = {-c,a,b};
    }
    sort(edge1,edge1+M);
    sort(edge2,edge2+M);
    int ans1 = 0;
    int cnt1 = 0;
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        tie(x,y,z) = edge1[i];
        if(!group(y,z))
        {
            continue;
        }
        ans1 += x;
        cnt1++;
        if(cnt1 == N)
        {
            break;
        }
    }
    ans1 = N-ans1;
    int ans2 = 0;
    int cnt2 = 0;
    for(int i=0;i<=N;i++)
    {
        v[i] = -1;
    }
    for(int i=0;i<M;i++)
    {
        int x,y,z;
        tie(x,y,z) = edge2[i];
        if(!group(y,z))
        {
            continue;
        }
        ans2 += x;
        cnt2++;
        if(cnt2 == N)
        {
            break;
        }
    }
    ans2 += N;
    cout << ans1 * ans1 - ans2 * ans2;

}
