#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int R[1005];
int G[1005];
int B[1005];
int dp[1005][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> R[i] >> G[i] >> B[i];
    }
    dp[0][0] = R[0];
    dp[0][1] = G[0];
    dp[0][2] = B[0];
    for(int i=1;i<N;i++)
    {
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + R[i];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + G[i];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + B[i]; 
    }
    cout << min({dp[N-1][0],dp[N-1][1],dp[N-1][2]});
}
