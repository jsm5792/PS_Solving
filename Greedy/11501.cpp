#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int a[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> N;
        for(int i=0;i<N;i++)
        {
            cin >> a[i];
        }
        long long ans =0;
        int max_a = a[N-1];
        for(int i=N-2;i>=0;i--)
        {
            if(a[i] > max_a)
            {
                max_a = a[i];
            }
            ans += max_a -a[i];
        }
        cout << ans << '\n';
    }
}
