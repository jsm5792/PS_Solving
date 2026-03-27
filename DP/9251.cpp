#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
string a,b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    for(int i=1;i<=a.length();i++)
    {
        for(int j=1;j<=b.length();j++)
        {
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    cout << dp[a.length()][b.length()];

}
