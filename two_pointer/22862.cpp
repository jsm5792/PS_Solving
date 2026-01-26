#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N,K;
int a[1000005];
int ans = -1;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    int end = 0;
    int cnt = 0;
    for(int start=0;start<N;start++)
    {
        while(end < N)
        {
            if(a[end]%2 ==1)
            {
                if(cnt < K)
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            end++;
        }
        ans = max(ans,end-start-cnt);
        cnt -= a[start]%2;
    }
    cout << ans;
}
