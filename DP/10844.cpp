#include <iostream>

using namespace std;
int N;
long long a[103][10];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=9;i++)
    {
        a[1][i]=1;
    }
    for(int i=2;i<=N;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(j!=0)
            {
                a[i][j] += a[i-1][j-1];
            }
            if(j!=9)
            {
                a[i][j] += a[i-1][j+1];
            }
            a[i][j] %= 1000000000;
        }
    }
    long long ans = 0;
    for(int i=0;i<=9;i++)
    {
        ans+=a[N][i];
    }
    ans%=1000000000;
    cout << ans;
}
