#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int temp=0;
    int sign=1;
    int ans=0;
    for(auto i: s)
    {
        if(i=='+' || i=='-')
        {
            ans += temp * sign;
            if(i=='-')
            {
                sign = -1;
            }
            temp = 0;
        }
        else
        {
            temp *=10;
            temp += i -'0';
        }
    }
    ans += temp * sign;
    cout << ans;
}
