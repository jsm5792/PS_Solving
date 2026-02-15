#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Planet{
    int cord;
    int index;

    bool operator<(const Planet& other) const
    {
        return this->cord < other.cord;
    }
};

int N;
tuple<int,int,int> edge[300005];
vector <int> v(100005,-1);
Planet X[100005],Y[100005],Z[100005];

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
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        X[i] = {a,i};
        Y[i] = {b,i};
        Z[i] = {c,i};
    }
    sort(X+1,X+N+1);
    sort(Y+1,Y+N+1);
    sort(Z+1,Z+N+1);
    int index = 0;
    for(int i=1;i<N;i++)
    {
        edge[index] = {abs(X[i].cord -X[i+1].cord), X[i].index,X[i+1].index};
        index ++;
        edge[index] = {abs(Y[i].cord -Y[i+1].cord), Y[i].index,Y[i+1].index};
        index ++;
        edge[index] = {abs(Z[i].cord -Z[i+1].cord), Z[i].index,Z[i+1].index};
        index ++;     
    }
    sort(edge,edge+index);

    long long ans = 0;
    int cnt =0;
    for(int i=0;i<index;i++)
    {
        int a,b,c;
        tie(a,b,c) = edge[i];
        if(!group(b,c))
        {
            continue;
        }
        cnt++;
        ans += a;
        if(cnt == N-1)
        {
            break;
        }
    }
    cout << ans;
}
