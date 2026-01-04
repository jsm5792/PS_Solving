#include <iostream>

using namespace std;

int a[502][502];
int b[502][502];
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin >> a[i][j];
            b[i][j] = max(b[i-1][j],b[i-1][j-1]) + a[i][j];
        }
    }
    int count =0;
    for(int j=1;j<=N;j++)
    {
        if(b[N][j] > count)
        {
            count = b[N][j];
        }
    }
    cout << count;
}
