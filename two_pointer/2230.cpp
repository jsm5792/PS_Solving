#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M;
int a[100005];
long long ans = 2000000005;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a,a+N);
    int end = 0;
    for(int i=0;i<N;i++)
    {
        while(end < N && a[end] - a[i] < M)
        {
            end++;
        }
        if(end==N)
        {
            break;
        }
        ans = min(ans, (long long)a[end]-a[i]);
        if(ans==M)
        {
            break;
        }
    }

    cout << ans;
}
