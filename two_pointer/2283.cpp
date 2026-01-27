#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,K;
int a[1000005];
long long ans;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        int x,y;
        cin >> x >> y;
        for(int j=x;j<y;j++)
        {
            a[j]++;
        }
    }
    int start = 0;
    int end = 0;
    while(end<=1000000)
    {
        if(ans < K)
        {
            ans += a[end];
            end++;
        }
        else if(ans > K)
        {
            ans -= a[start];
            start++;
        }
        else
        {
            cout << start << " " << end;
            return 0;
        }
    }
    cout << "0 0";
}
