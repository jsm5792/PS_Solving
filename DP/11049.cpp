#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int r[505], c[505];
int dp[505][505];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1;i<=N;i++)
    {
        cin >> r[i] >> c[i];
    }

    for(int len=1;len<N;len++)
    {
        for(int i=1;i<=N-len;i++)
        {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for(int k=i;k<j;k++)
            {
                int cost = dp[i][k] + dp[k+1][j] + (r[i] * c[k] * c[j]);
                if(dp[i][j] > cost)
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << dp[1][N];

}
