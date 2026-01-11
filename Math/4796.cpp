#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count =1;
    while(1)
    {
        int L,P,V;
        cin >> L >> P >> V;
        if(L==0)
        {
            break;
        }
        int ans = V/P * L + min(L,V%P);
        cout << "Case " << count << ": " << ans << '\n';
        count ++;
    }
}
