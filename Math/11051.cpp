#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int a[1005][1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,K;
    cin >> N >> K;
    for(int i=1;i<=N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j] = (a[i-1][j-1] + a[i-1][j]) %10007;
            }
        }
    }
    cout << a[N][K];
}
