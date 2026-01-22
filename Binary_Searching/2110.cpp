#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,C;
int a[200005];

bool solve(int x)
{
    int cnt = 1;
    int pos = a[0];
    for(int i=1;i<N;i++)
    {
        if(a[i]-pos >= x)
        {
            cnt++;
            pos = a[i];
        }
    }
    if(cnt >= C)
    {
        return true;
    }
    return false;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a,a+N);
    int start = 1;
    int end = a[N-1]-a[0];
    int ans = 1;
    while(start <= end)
    {
        int mid = (start+end)/2;
        if(solve(mid))
        {
            ans = mid;
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    cout << ans;

}
