#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
int a[4005];
int b[4005];
int c[4005];
int d[4005];
vector <int> x,y;
long long ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    x.reserve(N*N);
    y.reserve(N*N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            x.push_back(a[i]+b[j]);
            y.push_back(c[i]+d[j]);
        }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int x_temp =0;
    int y_temp = y.size()-1;
    while(x_temp < x.size() && y_temp >=0)
    {
        long long cur = x[x_temp] + y[y_temp];
        if(cur ==0)
        {
            long long x_1 = x[x_temp];
            long long y_1 = y[y_temp];
            long long cnt_x =0;
            long long cnt_y =0;
            while(x[x_temp]==x_1 && x_temp < x.size())
            {
                cnt_x++;
                x_temp++;
            }
            while(y[y_temp]==y_1 && y_temp >=0)
            {
                cnt_y++;
                y_temp--;
            }
            ans+= cnt_x * cnt_y;
        }
        else if(cur <0)
        {
            x_temp++;
        }
        else
        {
            y_temp--;
        }
    }
    cout << ans;

}
