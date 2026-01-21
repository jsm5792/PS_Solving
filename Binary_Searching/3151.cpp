#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int a[10005];
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a,a+N);
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            ans+= upper_bound(a+j+1, a+N, -a[i]-a[j]) - lower_bound(a+j+1,a+N,-a[i]-a[j]);
        }
    }
    cout << ans;
}
