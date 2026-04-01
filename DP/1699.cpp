#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int dp[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1;i<=N;i++)
    {
        dp[i]=i;
        for(int j=1;j*j<=i;j++)
        {
            if(dp[i]>dp[i-j*j]+1)
            {
                dp[i]=dp[i-j*j]+1;
            }
        }
    }

    cout << dp[N];

}
