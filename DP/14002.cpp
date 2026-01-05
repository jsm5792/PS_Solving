#include <iostream>

using namespace std;
int N;
int a[1001];
int b[1001];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                b[i] = max(b[i],b[j]+a[i]);
            }

        }
    }
    int ans = 0;
    for(int i=0;i<N;i++)
    {
        ans = max(b[i],ans);
    }
    cout << ans;


}
