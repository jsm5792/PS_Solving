#include <iostream>

using namespace std;

int N;
int a[100][2];
int b[100];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    int ans = 0;
    for(int i=N;i>0;i--)
    {
        if(a[i][0]+i-1 <= N)
        {
            b[i] = max(b[i+a[i][0]]+a[i][1],b[i+1]);
        }
        else
        {
            b[i] = b[i+1];
        }
        ans = max(b[i],ans);
    }
    cout << ans;
}
