#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;

void compress(vector <int>& v)
{
    vector<int> temp = v;
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    for(int &i :v)
    {
        i = lower_bound(temp.begin(),temp.end(),i) - temp.begin();
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    vector <vector<int>> universe(M, vector<int>(N));
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> universe[i][j];
        }
        compress(universe[i]);
    }
    int ans = 0;
    for(int i=0;i<M-1;i++)
    {
        for(int j=i+1;j<M;j++)
        {
            if(universe[i]==universe[j])
            {
                ans++;
            }
        }
    }
    cout << ans;
}
