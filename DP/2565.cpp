#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> v;
int dp[105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++)
    {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());

    int max_val = 0;
    for(int i=0;i<N;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(v[j].second < v[i].second)
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        max_val = max(max_val, dp[i]);
    }

    cout << N - max_val;

}
