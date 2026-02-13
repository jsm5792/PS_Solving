#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
vector <int> v(1005,-1);

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
    cin >> N;
    int index = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int cost;
            cin >> cost;
            if(i<j)
            {
                edge[index] = {cost,i,j};
                index++;
            }
        }
    }
    sort(edge,edge + index);
    int count = 0;
    long long ans = 0;
    for(int i=0;i<index;i++)
    {
        int x,y,z;
        tie(x,y,z) = edge[i];
        if(!group(y,z))
        {
            continue;
        }
        ans += x;
        count ++;
        if(count == N-1)
        {
            break;
        }
    }
    cout << ans;

}
