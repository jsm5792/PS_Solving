#include <iostream>

using namespace std;

int N;
int a[1500003];
int b[1500003][3];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> b[i][0] >> b[i][1];
    }
    for(int i=N;i>=1;i--)
    {
        if(b[i][0] + i-1 <= N)
        {
            a[i] = max(a[i+b[i][0]]+b[i][1] , a[i+1]);
        }
        else
        {
            a[i] = a[i+1];
        }
    }
    int ans = 0;
    for(int i=1;i<=N;i++)
    {
        ans = max(ans, a[i]);       
    }
    cout <<ans;


}
