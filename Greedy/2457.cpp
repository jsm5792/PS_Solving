#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int N;
int x[100005][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        x[i][0] = 100 * a + b;
        x[i][1] = 100 * c + d;
    }
    int count = 0;
    int time = 301;
    while(time <1201)
    {
        int temp=time;
        for(int i=0;i<N;i++)
        {
            if(x[i][0] <= time && x[i][1] > temp)
            {
                temp = x[i][1];                
            }
        }
        if(temp!= time)
        {
            count++;
            time = temp;
        }
        else
        {
            cout << 0;
            return 0;
        }
    }
    cout << count;
}
