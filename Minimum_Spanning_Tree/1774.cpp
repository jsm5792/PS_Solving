#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,M;

vector <pair<long long,long long>> loc(1005);
tuple<double,int,int> edge[500005];
vector <int> v(1005,-1);

int find(int x)
{
    if(v[x]<0)
    {
        return x;
    }
    return v[x] = find(v[x]);
}

bool group(int x, int y)
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
    for(int i=1;i<=N;i++)
    {
        cin >> loc[i].first >> loc[i].second;        
    }
    int index = 0;
    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            long long d1 = loc[j].first - loc[i].first;
            long long d2 = loc[j].second - loc[i].second;
            double d = sqrt(d1 * d1 + d2 * d2);
            edge[index] = {d,i,j};
            index++;
        }
    }
    int cnt =0;
    sort(edge,edge+index);
    for(int i=0;i<M;i++)
    {
        int x,y;
        cin >> x >> y;
        if(group(x,y))
        {
            cnt++;
        }
    }

    double ans = 0;
    
    for(int i=0;i<index;i++)
    {
        double x;
        int y,z;
        tie(x,y,z) = edge[i];
        if(!group(y,z))
        {
            continue;
        }
        ans += x;
        cnt++;
        if(cnt == N-1)
        {
            break;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
}
