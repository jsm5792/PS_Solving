#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,M,C;
int a[2005];
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C;
    cin >> M;
    vector <tuple<int,int,int>> v;
    for(int i=0;i<M;i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        v.push_back({to,from,weight});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<M;i++)
    {
        int load = 0;
        for(int j=get<1>(v[i]);j < get<0>(v[i]);j++)
        {
            load = max(load,a[j]);
        }
        if(load < C)
        {
            int temp;
            if(load + get<2>(v[i]) <= C)
            {
                temp = get<2>(v[i]);
            }
            else
            {
                temp = C - load;
            }
            for(int j=get<1>(v[i]);j< get<0>(v[i]);j++)
            {
                a[j]+= temp;
            }
            ans += temp;
        }
    }
    cout << ans;
}
