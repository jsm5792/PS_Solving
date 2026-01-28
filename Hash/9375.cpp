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
        unordered_map <string,int> s;
        int N;
        int ans=1;
        cin >> N;
        while(N--)
        {
            string a,b;
            cin >> a >> b;
            s[b]++;
        }
        for(auto i : s)
        {
            ans*= i.second + 1;
        }
        cout << ans-1 <<'\n';
        
    }
}
