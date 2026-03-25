#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,K;
int w[105];
int v[105];
int dp[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i=1;i<=N;i++)
    {
        cin >> w[i] >> v[i];
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=K;j>=w[i];j--)
        {
            if(dp[j] < dp[j-w[i]]+v[i])
            {
                dp[j] = dp[j-w[i]]+v[i];
            }
        }
    }

    cout << dp[K];

}
