#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int a[100005];
long long ans = 200000005;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    int start =0;
    int end = N-1;
    while(start < end)
    {
        if(abs(a[start]+a[end]) < abs(ans))
        {
            ans = a[start] + a[end];
        }
        if(a[start]+a[end]>0)
        {
            end--;
        }
        else
        {
            start ++;
        }
    }
    cout << ans;
}
