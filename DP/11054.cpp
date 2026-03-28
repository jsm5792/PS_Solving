#include <bits/stdc++.h>

using namespace std;

int N;
int a[1005];
int d_up[1005];
int d_down[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> a[i];
    }

    for(int i=1;i<=N;i++)
    {
        d_up[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i] && d_up[i]<d_up[j]+1)
            {
                d_up[i]=d_up[j]+1;
            }
        }
    }

    for(int i=N;i>=1;i--)
    {
        d_down[i]=1;
        for(int j=N;j>i;j--)
        {
            if(a[j]<a[i] && d_down[i]<d_down[j]+1)
            {
                d_down[i]=d_down[j]+1;
            }
        }
    }

    int ans=0;
    for(int i=1;i<=N;i++)
    {
        if(ans<d_up[i]+d_down[i]-1)
        {
            ans=d_up[i]+d_down[i]-1;
        }
    }

    cout << ans;

}
