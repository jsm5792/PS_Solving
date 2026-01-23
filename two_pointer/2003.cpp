#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,M,ans;
int a[10005];
long long b[10005];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++)
    {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    int end = 1;
    for(int i=1;i<=N;i++)
    {
        while(end <= N && b[end]-b[i-1]<M)
        {
            end++;
        }
        if(b[end]-b[i-1]==M)
        {
            ans++;
        }
        if(end==N && b[end]-b[i-1]<M)
        {
            break;
        }
    }
    cout << ans;
}
