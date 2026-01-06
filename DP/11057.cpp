#include <iostream>

using namespace std;
int N;
int a[1005][10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<10;i++)
    {
        a[1][i]=1;
    }
    for(int i=2;i<=N;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<=j;k++)
            {
                a[i][j] += a[i-1][k];
            }
            a[i][j] %= 10007;
        }
    }
    int ans =0;
    for(int i=0;i<=9;i++)
    {
        ans += a[N][i];
        ans %= 10007;
    }
    cout << ans;
}
