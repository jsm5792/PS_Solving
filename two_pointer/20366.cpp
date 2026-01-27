#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
int a[605];
int ans = 2e9;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a,a+N);
    for(int i=0;i<N;i++)
    {
        for(int j=i+3;j<N;j++)
        {
            int x = i+1;
            int y = j-1;
            while(x<y)
            {
                int temp = a[i]+a[j] - a[x]-a[y];
                ans = min(ans,abs(temp));
                if(temp > 0)
                {
                    x++;
                }
                else if(temp < 0)
                {
                    y--;
                }
                else
                {
                    cout << 0;
                    return 0;
                }

            }
        }
    }
    cout << ans;
}
