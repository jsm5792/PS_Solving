#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector <pair<int,int>> v;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    int ans=0;
    int temp_x=v[0].first;
    int temp_y=v[0].second;
    for(auto i : v)
    {
        if(i.first > temp_y)
        {
            ans += temp_y - temp_x;
            temp_x = i.first;
            temp_y = i.second;
        }
        else if(i.second > temp_y)
        {
            temp_y = i.second;
        }
    }
    ans += temp_y - temp_x;
    cout << ans;
}
