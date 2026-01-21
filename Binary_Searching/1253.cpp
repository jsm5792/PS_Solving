#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,ans;
int a[2005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a,a+N);
    for(int i=0;i<N;i++)
    {
        int temp = a[i];
        int start = 0;
        int end = N-1;
        while(start < end)
        {
            if(start == i)
            {
                start++;
                continue;
            }
            if(end==i)
            {
                end--;
                continue;
            }
            if(a[start]+a[end] == temp)
            {
                ans++;
                break;
            }
            if(a[start]+a[end]<temp)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }

    cout << ans;
}
