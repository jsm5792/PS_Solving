#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,L;
int a[55];

bool solve(int x)
{
    int cnt =0;
    for(int i=1;i<=N+1;i++)
    {
        int d = a[i] - a[i-1];
        cnt += (d - 1) / x;
    }
    return M >= cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> L;
    for(int i=1;i<=N;i++)
    {
        cin >> a[i];
    }
    a[0]=0;
    a[N+1]=L;
    sort(a,a+N+2);
    int start = 1;
    int end = L;
    while(start < end)
    {
        int mid = (start + end)/2;
        if(solve(mid))
        {
            end = mid;
        }
        else
        {
            start = mid+1;
        }
    }
    cout << start;
}
