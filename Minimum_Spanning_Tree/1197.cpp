#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <int> v(10005,-1);
int a,b;
tuple<int,int,int> edge[100005];

int find(int x)
{
    if(v[x] <0)
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
    cin >> a >> b;
    for(int i=0;i<b;i++)
    {
        int x,y,cost;
        cin >> x >> y >> cost;
        edge[i] = {cost,x,y};
    }
    sort(edge,edge+b);
    int count =0;
    int ans = 0;
    for(int i=0;i<b;i++)
    {
        int x,y,cost;
        tie(cost,x,y) = edge[i];
        if(!group(x,y))
        {
            continue;
        }
        ans += cost;
        count ++;
        if(count == a-1)
        {
            break;
        }
    }
    cout << ans;
}
