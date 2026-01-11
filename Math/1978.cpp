#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, ans;
bool a[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    a[2]=true;
    for(int i=3;i<1001;i++)
    {
        a[i] = true;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                a[i]= false;
                break;
            }
        }   
    }

    for(int i=0;i<N;i++)
    {
        int num;
        cin >> num;
        if(a[num])
        {
            ans++;
        }
    }
    cout << ans;
}
