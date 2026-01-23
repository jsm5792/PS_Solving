#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,d,k,c,ans;
int a[30005];
int b[3005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> d >> k >> c;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    int curr = 0;
    for(int i=0;i<k;i++)
    {
        if(b[a[i]]==0)
        {
            curr++;
        }
        b[a[i]]++;
    }
    ans = curr;
    for(int i=0;i<N;i++)
    {
        b[a[i]]--;
        if(b[a[i]]==0)
        {
            curr--;
        }
        int next = (i+k)%N;
        if(b[a[next]]==0)
        {
            curr++;
        }
        b[a[next]]++;
        if(b[c]==0)
        {
            ans = max(curr+1,ans);
        }
        else
        {
            ans = max(curr,ans);
        }
    }
    cout << ans;





}
