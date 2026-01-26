#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,M;
int a[1005];
int ans = 2e9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    vector<pair<int,int>> v;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int temp;
            cin >> temp;
            v.push_back({temp,i});
        }
    }
    sort(v.begin(),v.end());
    int end=0;
    int cnt=0;
    for(int start=0;start<v.size();start++)
    {
        while(end < v.size() && cnt < N)
        {
            if(a[v[end].second]==0)
            {
                cnt++;
            }
            a[v[end].second]++;
            end++;
        }
        if(cnt==N)
        {
            ans = min(ans,v[end-1].first - v[start].first);
        }
        a[v[start].second]--;
        if(a[v[start].second]==0)
        {
            cnt--;
        }
    }
    cout << ans;
}
