#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        long long x,y;
        cin >> x >> y;
        long long ans = (long long) sqrt(y-x);
        if(ans * ans == y-x)
        {
            cout << 2*ans - 1 <<'\n';
        }
        else if(y-x <= ans * ans + ans)
        {
            cout << 2*ans << '\n';
        }
        else
        {
            cout << 2*ans +1<<'\n';
        }

    }
}