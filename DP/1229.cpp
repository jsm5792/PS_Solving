#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    vector<int> hex;
    for(int i=1;;i++)
    {
        int h=i*(2*i-1);
        if(h > N)
        {
            break;
        }
        hex.push_back(h);
    }

    vector<int> dp(N + 1, 7);
    dp[0] = 0;

    for(auto h : hex)
    {
        for(int i=h;i<=N;i++)
        {
            if(dp[i-h] != 7)
            {
                dp[i] = min(dp[i], dp[i-h] + 1);
            }
        }
    }

    cout << dp[N];
}
