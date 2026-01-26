#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N,K,ans;
int a[200005];
int b[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    int end=0;
    for(int start=0;start<N;start++)
    {
        while(end<N)
        {
            if(b[a[end]] <K)
            {
                b[a[end]]++;
            }
            else
            {
                break;
            }
            end++;
        }
        ans = max(ans,end-start);
        b[a[start]]--;
    }
    cout << ans;
    
}
