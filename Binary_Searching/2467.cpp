#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int a[100005];
int x,y;
long long ans=2000000005;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    int start = 0;
    int end = N-1;
    while(start < end)
    {
        if(abs(ans) > abs(a[start]+a[end]))
        {
            x = start;
            y = end;
            ans = a[start]+a[end];
        }
        if(a[start]+a[end]<0)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    cout << a[x] << ' '<<a[y];
}
