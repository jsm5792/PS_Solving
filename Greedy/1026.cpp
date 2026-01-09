#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int a[100];
int b[100];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<N;i++)
    {
        cin >> b[i];
    }
    
    sort(a,a+N);
    sort(b,b+N);
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        ans += a[i]*b[N-1-i];
    }
    cout << ans;
}
