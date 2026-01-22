#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
long long a[5005];
long long ans = 3000000005;
int x,y,z;

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
        int temp_x = 0;
        int temp_y = N-1;
        while(temp_x < temp_y)
        {
            if(temp_x == i)
            {
                temp_x++;
                continue;
            }
            if(temp_y == i)
            {
                temp_y--;
                continue;
            }
            if(abs(a[temp_x]+ a[temp_y]+a[i]) < abs(ans))
            {
                ans = a[temp_x] + a[temp_y] +a[i];
                x = min(temp_x,i);
                z = max(temp_y,i);
                y = temp_x + i + temp_y - x - z;
                if(ans ==0)
                {
                    cout << a[x] << ' '<< a[y] <<' '<<a[z];
                    return 0;
                }
            }
            if(a[temp_x]+a[temp_y]+a[i] < 0)
            {
                temp_x ++;
            }
            else
            {
                temp_y--;
            }
        }
    }
    cout << a[x] << ' '<< a[y] << ' '<<a[z];

}
